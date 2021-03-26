# KAIMyEntity
Replace Minecraft entity with MMD model.

## KAIMyEntitySaba
将Github项目 benikabocha/saba (https://github.com/benikabocha/saba) 魔改成一个以JNI形式Export函数的动态链接库。
依赖头文件：bullet, glm, spdlog, stb
依赖库文件：bullet (已编译在KAIMyEntitySaba\bullet\lib)

## KAIMyEntity_1.12.2 & KAIMyEntity_1.16.5
API: Forge
接入KAIMyEntitySaba.dll，负责Hook Minecraft的渲染器。
如果可以的话，所有的活儿我都想交给C++侧去做。
但是OpenGL会话由Java发起，因此只能写Java的渲染器。