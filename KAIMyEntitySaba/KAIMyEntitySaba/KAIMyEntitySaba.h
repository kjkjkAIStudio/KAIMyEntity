#ifndef _KAIMYENTITY_H_
#define _KAIMYENTITY_H_

#include <memory>
#include <Saba/Model/MMD/PMXModel.h>
#include <Saba/Model/MMD/PMDModel.h>
#include <Saba/Model/MMD/VMDAnimation.h>

namespace KAIMyEntitySaba
{
	struct Texture
	{
		uint8_t* data;
		int x, y;
		bool hasAlpha;
	};

	struct Model
	{
		std::shared_ptr<saba::MMDModel> mmdModel;
		size_t vmdAnimCount;
		saba::VMDAnimation** vmdAnims;
		double* animTimes;
		double prevSabaTime;
	};

	Model* LoadModelPMX(const char* filename, const char* dir, size_t layerCount);
	Model* LoadModelPMD(const char* filename, const char* dir, size_t layerCount);
	void DeleteModel(Model* model);
	void UpdateModel(Model* model);

	size_t GetVertexCount(Model* model);
	const void* GetPoss(Model* model); //float * 3
	const void* GetNormals(Model* model); //float * 3
	const void* GetUVs(Model* model); //float * 2
	size_t GetIndexElementSize(Model* model);
	size_t GetIndexCount(Model* model);
	const void* GetIndices(Model* model);
	size_t GetMaterialCount(Model* model);
	const char* GetMaterialTex(Model* model, size_t pos);
	const char* GetMaterialSpTex(Model* model, size_t pos);
	const char* GetMaterialToonTex(Model* model, size_t pos);
	const void* GetMaterialAmbient(Model* model, size_t pos); //float * 3
	const void* GetMaterialDiffuse(Model* model, size_t pos); //float * 3
	const void* GetMaterialSpecular(Model* model, size_t pos); //float * 3
	float GetMaterialSpecularPower(Model* model, size_t pos);
	float GetMaterialAlpha(Model* model, size_t pos);
	const void* GetMaterialTextureMulFactor(Model* model, size_t pos); //float * 4
	const void* GetMaterialTextureAddFactor(Model* model, size_t pos); //float * 4
	int GetMaterialSpTextureMode(Model* model, size_t pos);
	const void* GetMaterialSpTextureMulFactor(Model* model, size_t pos); //float * 4
	const void* GetMaterialSpTextureAddFactor(Model* model, size_t pos); //float * 4
	const void* GetMaterialToonTextureMulFactor(Model* model, size_t pos); //float * 4
	const void* GetMaterialToonTextureAddFactor(Model* model, size_t pos); //float * 4
	bool GetMaterialBothFace(Model* model, size_t pos);
	size_t GetSubMeshCount(Model* model);
	int GetSubMeshMaterialID(Model* model, size_t pos);
	int GetSubMeshBeginIndex(Model* model, size_t pos);
	int GetSubMeshVertexCount(Model* model, size_t pos);
	void ChangeModelAnim(Model* model, saba::VMDAnimation* anim, size_t layer);
	void ResetModelPhysics(Model* model);

	glm::mat4* CreateMat();
	void DeleteMat(glm::mat4* mat);
	void GetRightHandMat(Model* model, glm::mat4* mat);
	void GetLeftHandMat(Model* model, glm::mat4* mat);

	Texture* LoadTexture(const char* filename);
	void DeleteTexture(Texture* tex);
	int GetTextureX(Texture* tex);
	int GetTextureY(Texture* tex);
	const void* GetTextureData(Texture* tex);
	bool TextureHasAlpha(Texture* tex);

	saba::VMDAnimation* LoadAnimation(Model* model, const char* filename);
	void DeleteAnimation(saba::VMDAnimation* anim);
}

#endif