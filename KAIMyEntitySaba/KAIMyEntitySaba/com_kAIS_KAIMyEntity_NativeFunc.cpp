#include "com_kAIS_KAIMyEntity_NativeFunc.h"

#include "KAIMyEntitySaba.h"

using namespace KAIMyEntitySaba;

JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetVersion(JNIEnv* env, jobject obj)
{
	return env->NewStringUTF("1.1b4");
}

JNIEXPORT jbyte JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ReadByte(JNIEnv* env, jobject obj, jlong data, jlong pos)
{
	return (unsigned char)*(((unsigned char*)data) + pos);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_CopyDataToByteBuffer(JNIEnv* env, jobject obj, jobject buffer, jlong data, jlong length)
{
	unsigned char* p = (unsigned char*)env->GetDirectBufferAddress(buffer);
	for (int i = 0; i < length; ++i)
		(*(p + i)) = (*((unsigned char*)data + i));
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadModelPMX(JNIEnv* env, jobject obj, jstring filename, jstring dir, jlong layerCount)
{
	return (unsigned long long)LoadModelPMX(env->GetStringUTFChars(filename, JNI_FALSE), env->GetStringUTFChars(dir, JNI_FALSE), layerCount);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadModelPMD(JNIEnv* env, jobject obj, jstring filename, jstring dir, jlong layerCount)
{
	return (unsigned long long)LoadModelPMD(env->GetStringUTFChars(filename, JNI_FALSE), env->GetStringUTFChars(dir, JNI_FALSE), layerCount);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteModel(JNIEnv* env, jobject obj, jlong model)
{
	DeleteModel((Model*)model);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_UpdateModel(JNIEnv* env, jobject obj, jlong model)
{
	UpdateModel((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetVertexCount(JNIEnv* env, jobject obj, jlong model)
{
	return GetVertexCount((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetPoss(JNIEnv* env, jobject obj, jlong model)
{
	return (unsigned long long)GetPoss((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetNormals(JNIEnv* env, jobject obj, jlong model)
{
	return (unsigned long long)GetNormals((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetUVs(JNIEnv* env, jobject obj, jlong model)
{
	return (unsigned long long)GetUVs((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndexElementSize(JNIEnv* env, jobject obj, jlong model)
{
	return GetIndexElementSize((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndexCount(JNIEnv* env, jobject obj, jlong model)
{
	return GetIndexCount((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndices(JNIEnv* env, jobject obj, jlong model)
{
	return (unsigned long long)GetIndices((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialCount(JNIEnv* env, jobject obj, jlong model)
{
	return GetMaterialCount((Model*)model);
}

JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTex(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return env->NewStringUTF(GetMaterialTex((Model*)model, pos));
}

JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTex(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return env->NewStringUTF(GetMaterialSpTex((Model*)model, pos));
}

JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTex(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return env->NewStringUTF(GetMaterialToonTex((Model*)model, pos));
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialAmbient(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialAmbient((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialDiffuse(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialDiffuse((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpecular(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialSpecular((Model*)model, pos);
}

JNIEXPORT jfloat JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpecularPower(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetMaterialSpecularPower((Model*)model, pos);
}

JNIEXPORT jfloat JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialAlpha(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetMaterialAlpha((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialTextureMulFactor((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialTextureAddFactor((Model*)model, pos);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureMode(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetMaterialSpTextureMode((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialSpTextureMulFactor((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialSpTextureAddFactor((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialToonTextureMulFactor((Model*)model, pos);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return (unsigned long long)GetMaterialToonTextureAddFactor((Model*)model, pos);
}

JNIEXPORT jboolean JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialBothFace(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetMaterialBothFace((Model*)model, pos) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshCount(JNIEnv* env, jobject obj, jlong model)
{
	return GetSubMeshCount((Model*)model);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshMaterialID(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetSubMeshMaterialID((Model*)model, pos);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshBeginIndex(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetSubMeshBeginIndex((Model*)model, pos);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshVertexCount(JNIEnv* env, jobject obj, jlong model, jlong pos)
{
	return GetSubMeshVertexCount((Model*)model, pos);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ChangeModelAnim(JNIEnv* env, jobject obj, jlong model, jlong anim, jlong layer)
{
	ChangeModelAnim((Model*)model, (saba::VMDAnimation*)anim, layer);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ResetModelPhysics(JNIEnv* env, jobject obj, jlong model)
{
	ResetModelPhysics((Model*)model);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_CreateMat(JNIEnv* env, jobject obj)
{
	return (unsigned long long)CreateMat();
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteMat(JNIEnv* env, jobject obj, jlong mat)
{
	DeleteMat((glm::mat4*)mat);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetRightHandMat(JNIEnv* env, jobject obj, jlong model, jlong mat)
{
	GetRightHandMat((Model*)model, (glm::mat4*)mat);
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetLeftHandMat(JNIEnv* env, jobject obj, jlong model, jlong mat)
{
	GetLeftHandMat((Model*)model, (glm::mat4*)mat);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadTexture(JNIEnv* env, jobject obj, jstring filename)
{
	return (unsigned long long)LoadTexture(env->GetStringUTFChars(filename, JNI_FALSE));
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteTexture(JNIEnv* env, jobject obj, jlong tex)
{
	DeleteTexture((Texture*)tex);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureX(JNIEnv* env, jobject obj, jlong tex)
{
	return GetTextureX((Texture*)tex);
}

JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureY(JNIEnv* env, jobject obj, jlong tex)
{
	return GetTextureY((Texture*)tex);
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureData(JNIEnv* env, jobject obj, jlong tex)
{
	return (unsigned long long)GetTextureData((Texture*)tex);
}

JNIEXPORT jboolean JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_TextureHasAlpha(JNIEnv* env, jobject obj, jlong tex)
{
	return TextureHasAlpha((Texture*)tex) ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadAnimation(JNIEnv* env, jobject obj, jlong model, jstring filename)
{
	return (unsigned long long)LoadAnimation((Model*)model, env->GetStringUTFChars(filename, JNI_FALSE));
}

JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteAnimation(JNIEnv* env, jobject obj, jlong anim)
{
	DeleteAnimation((saba::VMDAnimation*)anim);
}