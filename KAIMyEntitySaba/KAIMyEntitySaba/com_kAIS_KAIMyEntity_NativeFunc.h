#include "jni.h"

#ifndef _Included_com_kAIS_KAIMyEntity_NativeFunc
#define _Included_com_kAIS_KAIMyEntity_NativeFunc
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetVersion(JNIEnv* env, jobject obj);
	JNIEXPORT jbyte JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ReadByte(JNIEnv* env, jobject obj, jlong data, jlong pos);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_CopyDataToByteBuffer(JNIEnv* env, jobject obj, jobject buffer, jlong data, jlong len);

	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadModelPMX(JNIEnv* env, jobject obj, jstring filename, jstring dir, jlong layerCount);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadModelPMD(JNIEnv* env, jobject obj, jstring filename, jstring dir, jlong layerCount);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteModel(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_UpdateModel(JNIEnv* env, jobject obj, jlong model);

	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetVertexCount(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetPoss(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetNormals(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetUVs(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndexElementSize(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndexCount(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetIndices(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialCount(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTex(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTex(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jstring JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTex(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialAmbient(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialDiffuse(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpecular(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jfloat JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpecularPower(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jfloat JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialAlpha(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureMode(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialSpTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTextureMulFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialToonTextureAddFactor(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jboolean JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetMaterialBothFace(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshCount(JNIEnv* env, jobject obj, jlong model);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshMaterialID(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshBeginIndex(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetSubMeshVertexCount(JNIEnv* env, jobject obj, jlong model, jlong pos);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ChangeModelAnim(JNIEnv* env, jobject obj, jlong model, jlong anim, jlong layer);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_ResetModelPhysics(JNIEnv* env, jobject obj, jlong model);

	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_CreateMat(JNIEnv* env, jobject obj);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteMat(JNIEnv* env, jobject obj, jlong mat);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetRightHandMat(JNIEnv* env, jobject obj, jlong model, jlong mat);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetLeftHandMat(JNIEnv* env, jobject obj, jlong model, jlong mat);

	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadTexture(JNIEnv* env, jobject obj, jstring filename);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteTexture(JNIEnv* env, jobject obj, jlong tex);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureX(JNIEnv* env, jobject obj, jlong tex);
	JNIEXPORT jint JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureY(JNIEnv* env, jobject obj, jlong tex);
	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_GetTextureData(JNIEnv* env, jobject obj, jlong tex);
	JNIEXPORT jboolean JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_TextureHasAlpha(JNIEnv* env, jobject obj, jlong tex);

	JNIEXPORT jlong JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_LoadAnimation(JNIEnv* env, jobject obj, jlong model, jstring filename);
	JNIEXPORT void JNICALL Java_com_kAIS_KAIMyEntity_NativeFunc_DeleteAnimation(JNIEnv* env, jobject obj, jlong anim);

#ifdef __cplusplus
}
#endif
#endif
