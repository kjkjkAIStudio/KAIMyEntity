package com.kAIS.KAIMyEntity;

import net.minecraft.client.Minecraft;

import java.io.File;
import java.nio.ByteBuffer;

public class NativeFunc
{
    public static NativeFunc GetInst()
    {
        if (inst == null)
        {
            String[] dependencyArray = new String[]
                    {
                            "KERNEL32.dll",
                            "MSVCP140.dll",
                            "VCRUNTIME140.dll",
                            "VCRUNTIME140_1.dll",
                            "api-ms-win-crt-convert-l1-1-0.dll",
                            "api-ms-win-crt-heap-l1-1-0.dll",
                            "api-ms-win-crt-locale-l1-1-0.dll",
                            "api-ms-win-crt-math-l1-1-0.dll",
                            "api-ms-win-crt-runtime-l1-1-0.dll",
                            "api-ms-win-crt-stdio-l1-1-0.dll",
                            "api-ms-win-crt-string-l1-1-0.dll",
                            "api-ms-win-crt-time-l1-1-0.dll"
                    };
            boolean missingDependencies = false;
            for (String i : dependencyArray)
            {
                File f = new File(System.getenv("SystemRoot") + "\\System32", i);
                if (!f.exists())
                {
                    //"api-ms-win-crt-xxx" may in this directory
                    f = new File(System.getenv("SystemRoot") + "\\System32\\downlevel", i);
                    if (!f.exists())
                    {
                        missingDependencies = true;
                        KAIMyEntity.logger.info(String.format("Cannot find dependency of KAIMyEntitySaba.dll. Named \"%s\".", i));
                    }
                }
            }
            if (missingDependencies)
            {
                KAIMyEntity.logger.info("Some dependencies of KAIMyEntitySaba.dll is missing! Try installing Microsoft Visual C++ 2015 Redistributable (x64). If it still not work, you need to search for the dll and put it into your system32 folder.");
            }
            try
            {
                System.load(new File(Minecraft.getMinecraft().mcDataDir, "mods\\KAIMyEntitySaba.dll").getAbsolutePath());
            }
            catch (Throwable e)
            {
                KAIMyEntity.logger.info("Cannot load native library: KAIMyEntitySaba.dll.");
                throw e;
            }
            inst = new NativeFunc();
        }

        return inst;
    }

    public native String GetVersion();
    public native byte ReadByte(long data, long pos);
    public native void CopyDataToByteBuffer(ByteBuffer buffer, long data, long pos);

    public native long LoadModelPMX(String filename, String dir, long layerCount);
    public native long LoadModelPMD(String filename, String dir, long layerCount);
    public native void DeleteModel(long model);
    public native void UpdateModel(long model);

    public native long GetVertexCount(long model);
    public native long GetPoss(long model);
    public native long GetNormals(long model);
    public native long GetUVs(long model);
    public native long GetIndexElementSize(long model);
    public native long GetIndexCount(long model);
    public native long GetIndices(long model);
    public native long GetMaterialCount(long model);
    public native String GetMaterialTex(long model, long pos);
    public native String GetMaterialSpTex(long model, long pos);
    public native String GetMaterialToonTex(long model, long pos);
    public native long GetMaterialAmbient(long model, long pos);
    public native long GetMaterialDiffuse(long model, long pos);
    public native long GetMaterialSpecular(long model, long pos);
    public native float GetMaterialSpecularPower(long model, long pos);
    public native float GetMaterialAlpha(long model, long pos);
    public native long GetMaterialTextureMulFactor(long model, long pos);
    public native long GetMaterialTextureAddFactor(long model, long pos);
    public native int GetMaterialSpTextureMode(long model, long pos);
    public native long GetMaterialSpTextureMulFactor(long model, long pos);
    public native long GetMaterialSpTextureAddFactor(long model, long pos);
    public native long GetMaterialToonTextureMulFactor(long model, long pos);
    public native long GetMaterialToonTextureAddFactor(long model, long pos);
    public native boolean GetMaterialBothFace(long model, long pos);
    public native long GetSubMeshCount(long model);
    public native int GetSubMeshMaterialID(long model, long pos);
    public native int GetSubMeshBeginIndex(long model, long pos);
    public native int GetSubMeshVertexCount(long model, long pos);
    public native void ChangeModelAnim(long model, long anim, long layer);
    public native void ResetModelPhysics(long model);

    public native long CreateMat();
    public native void DeleteMat(long mat);
    public native void GetRightHandMat(long model, long mat);
    public native void GetLeftHandMat(long model, long mat);

    public native long LoadTexture(String filename);
    public native void DeleteTexture(long tex);
    public native int GetTextureX(long tex);
    public native int GetTextureY(long tex);
    public native long GetTextureData(long tex);
    public native boolean TextureHasAlpha(long tex);

    public native long LoadAnimation(long model, String filename);
    public native void DeleteAnimation(long anim);

    static NativeFunc inst;

    NativeFunc()
    {
    }
}
