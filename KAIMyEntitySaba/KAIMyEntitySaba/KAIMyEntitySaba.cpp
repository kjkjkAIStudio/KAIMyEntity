#include "KAIMyEntitySaba.h"

#define	STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb/stb_image.h>
#include <Saba/Base/Time.h>

using namespace KAIMyEntitySaba;

const int FPS = 30;
const float PHYSICS_ELAPSED = 1.0f / FPS;

Model* KAIMyEntitySaba::LoadModelPMX(const char* filename, const char* dir, size_t layerCount)
{
	auto model = std::make_unique<saba::PMXModel>();
	if (!model->Load(filename, dir))
	{
		model.reset();
		return nullptr;
	}
	model->InitializeAnimation();
	model->ResetPhysics();

	auto vmdAnims = new saba::VMDAnimation*[layerCount];
	for (size_t i = 0; i < layerCount; ++i)
		vmdAnims[i] = nullptr;
	auto animTimes = new double[layerCount];
	for (int i = 0; i < layerCount; ++i)
		animTimes[i] = 0.0;

	Model* result = new Model;
	result->mmdModel = std::move(model);
	result->vmdAnims = vmdAnims;
	result->vmdAnimCount = layerCount;
	result->animTimes = animTimes;
	result->prevSabaTime = saba::GetTime();

	return result;
}

Model* KAIMyEntitySaba::LoadModelPMD(const char* filename, const char* dir, size_t layerCount)
{
	auto model = std::make_unique<saba::PMDModel>();
	if (!model->Load(filename, dir))
	{
		model.reset();
		return nullptr;
	}
	model->InitializeAnimation();
	model->ResetPhysics();

	auto vmdAnims = new saba::VMDAnimation*[layerCount];
	for (int i = 0; i < layerCount; ++i)
		vmdAnims[i] = nullptr;
	auto animTimes = new double[layerCount];
	for (int i = 0; i < layerCount; ++i)
		animTimes[i] = 0.0;

	Model* result = new Model;
	result->mmdModel = std::move(model);
	result->vmdAnims = vmdAnims;
	result->vmdAnimCount = layerCount;
	result->animTimes = animTimes;
	result->prevSabaTime = saba::GetTime();

	return result;
}

void KAIMyEntitySaba::DeleteModel(Model* model)
{
	delete[] model->animTimes;
	delete[] model->vmdAnims;
	model->mmdModel.reset();
	delete model;
}

void KAIMyEntitySaba::UpdateModel(Model* model)
{
	double deltaTime = saba::GetTime() - model->prevSabaTime;
	model->prevSabaTime = saba::GetTime();
	double elapsed = deltaTime;
	if (elapsed > PHYSICS_ELAPSED)
		elapsed = PHYSICS_ELAPSED;
	model->mmdModel->BeginAnimation();
	for (size_t i = 0; i < model->vmdAnimCount; ++i)
	{
		auto vmdAnim = model->vmdAnims[i];
		if (vmdAnim != nullptr)
		{
			double animTime = model->animTimes[i] + deltaTime;
			if (animTime * FPS > vmdAnim->GetMaxKeyTime())
				animTime = 0.0;
			model->animTimes[i] = animTime;
			model->mmdModel->UpdateAllAnimation(vmdAnim, animTime * FPS, elapsed);
		}
	}
	model->mmdModel->EndAnimation();
	model->mmdModel->Update();
}

size_t KAIMyEntitySaba::GetVertexCount(Model* model)
{
	return model->mmdModel->GetVertexCount();
}

const void* KAIMyEntitySaba::GetPoss(Model* model)
{
	return model->mmdModel->GetUpdatePositions();
}

const void* KAIMyEntitySaba::GetNormals(Model* model)
{
	return model->mmdModel->GetUpdateNormals();
}

const void* KAIMyEntitySaba::GetUVs(Model* model)
{
	return model->mmdModel->GetUpdateUVs();
}

size_t KAIMyEntitySaba::GetIndexElementSize(Model* model)
{
	return model->mmdModel->GetIndexElementSize();
}

size_t KAIMyEntitySaba::GetIndexCount(Model* model)
{
	return model->mmdModel->GetIndexCount();
}

const void* KAIMyEntitySaba::GetIndices(Model* model)
{
	return model->mmdModel->GetIndices();
}

size_t KAIMyEntitySaba::GetMaterialCount(Model* model)
{
	return model->mmdModel->GetMaterialCount();
}

const char* KAIMyEntitySaba::GetMaterialTex(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_texture.c_str();
}

const char* KAIMyEntitySaba::GetMaterialSpTex(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_spTexture.c_str();
}

const char* KAIMyEntitySaba::GetMaterialToonTex(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_toonTexture.c_str();
}

const void* KAIMyEntitySaba::GetMaterialAmbient(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_ambient);
}

const void* KAIMyEntitySaba::GetMaterialDiffuse(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_diffuse);
}

const void* KAIMyEntitySaba::GetMaterialSpecular(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_specular);
}

float KAIMyEntitySaba::GetMaterialSpecularPower(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_specularPower;
}

float KAIMyEntitySaba::GetMaterialAlpha(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_alpha;
}

const void* KAIMyEntitySaba::GetMaterialTextureMulFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_textureMulFactor);
}

const void* KAIMyEntitySaba::GetMaterialTextureAddFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_textureAddFactor);
}

int KAIMyEntitySaba::GetMaterialSpTextureMode(Model* model, size_t pos)
{
	return (int)model->mmdModel->GetMaterials()[pos].m_spTextureMode;
}

const void* KAIMyEntitySaba::GetMaterialSpTextureMulFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_spTextureMulFactor);
}

const void* KAIMyEntitySaba::GetMaterialSpTextureAddFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_spTextureAddFactor);
}

const void* KAIMyEntitySaba::GetMaterialToonTextureMulFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_toonTextureMulFactor);
}

const void* KAIMyEntitySaba::GetMaterialToonTextureAddFactor(Model* model, size_t pos)
{
	return &(model->mmdModel->GetMaterials()[pos].m_toonTextureAddFactor);
}

bool KAIMyEntitySaba::GetMaterialBothFace(Model* model, size_t pos)
{
	return model->mmdModel->GetMaterials()[pos].m_bothFace;
}

size_t KAIMyEntitySaba::GetSubMeshCount(Model* model)
{
	return model->mmdModel->GetSubMeshCount();
}

int KAIMyEntitySaba::GetSubMeshMaterialID(Model* model, size_t pos)
{
	return model->mmdModel->GetSubMeshes()[pos].m_materialID;
}

int KAIMyEntitySaba::GetSubMeshBeginIndex(Model* model, size_t pos)
{
	return model->mmdModel->GetSubMeshes()[pos].m_beginIndex;
}

int KAIMyEntitySaba::GetSubMeshVertexCount(Model* model, size_t pos)
{
	return model->mmdModel->GetSubMeshes()[pos].m_vertexCount;
}

void KAIMyEntitySaba::ChangeModelAnim(Model* model, saba::VMDAnimation* anim, size_t layer)
{
	model->mmdModel->InitializeAnimation();
	model->vmdAnims[layer] = anim;
	model->prevSabaTime = saba::GetTime();
	model->animTimes[layer] = 0.0;
}

void KAIMyEntitySaba::ResetModelPhysics(Model* model)
{
	model->mmdModel->ResetPhysics();
}

glm::mat4* KAIMyEntitySaba::CreateMat()
{
	glm::mat4* result = new glm::mat4;
	return result;
}

void KAIMyEntitySaba::DeleteMat(glm::mat4* mat)
{
	delete mat;
}

void KAIMyEntitySaba::GetRightHandMat(Model* model, glm::mat4* mat)
{
	const char name[] = { 0xE5, 0x8F, 0xB3, 0xE4, 0xB8, 0xAD, 0xE6, 0x8C, 0x87, 0xEF, 0xBC, 0x91, 0x00 }; //Japanese name of bone by UTF8
	saba::MMDNode* node = model->mmdModel->GetNodeManager()->GetMMDNode(name);
	if (node == nullptr)
		return;
	*mat = node->GetGlobalTransform();
}

void KAIMyEntitySaba::GetLeftHandMat(Model* model, glm::mat4* mat)
{
	const char name[] = { 0xE5, 0xB7, 0xA6, 0xE4, 0xB8, 0xAD, 0xE6, 0x8C, 0x87, 0xEF, 0xBC, 0x91, 0x00 }; //Japanese name of bone by UTF8
	saba::MMDNode* node = model->mmdModel->GetNodeManager()->GetMMDNode(name);
	if (node == nullptr)
		return;
	*mat = node->GetGlobalTransform();
}

Texture* KAIMyEntitySaba::LoadTexture(const char* filename)
{
	saba::File file;
	if (!file.Open(filename))
		return nullptr;

	stbi_set_flip_vertically_on_load(true);
	int x, y, comp;
	int ret = stbi_info_from_file(file.GetFilePointer(), &x, &y, &comp);
	if (ret == 0)
		return nullptr;
	uint8_t* data;
	bool hasAlpha;
	if (comp != 4)
	{
		data = stbi_load_from_file(file.GetFilePointer(), &x, &y, &comp, STBI_rgb);
		hasAlpha = false;
	}
	else
	{
		data = stbi_load_from_file(file.GetFilePointer(), &x, &y, &comp, STBI_rgb_alpha);
		hasAlpha = true;
	}

	Texture* result = new Texture;
	result->data = data;
	result->x = x;
	result->y = y;
	result->hasAlpha = hasAlpha;
	return result;
}

void KAIMyEntitySaba::DeleteTexture(Texture* tex)
{
	stbi_image_free(tex->data);
	delete tex;
}

int KAIMyEntitySaba::GetTextureX(Texture* tex)
{
	return tex->x;
}

int KAIMyEntitySaba::GetTextureY(Texture* tex)
{
	return tex->y;
}

const void* KAIMyEntitySaba::GetTextureData(Texture* tex)
{
	return tex->data;
}

bool KAIMyEntitySaba::TextureHasAlpha(Texture* tex)
{
	return tex->hasAlpha;
}

saba::VMDAnimation* KAIMyEntitySaba::LoadAnimation(Model* model, const char* filename)
{
	saba::VMDFile vmd;
	if (!saba::ReadVMDFile(&vmd, filename))
		return nullptr;
	saba::VMDAnimation* result = new saba::VMDAnimation;
	result->Create(model->mmdModel);
	result->Add(vmd);
	result->SyncPhysics(0.0f, FPS);

	return result;
}

void KAIMyEntitySaba::DeleteAnimation(saba::VMDAnimation* anim)
{
	delete anim;
}