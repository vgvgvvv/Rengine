//
// Created by ¶­å· on 2018/5/1.
//

#include <Lua/lua.hpp>
#include "LuaEngine.hpp"


const lua_State *ReEngine::LuaEngine::GetLuaState() {
    return nullptr;
}

bool ReEngine::LuaEngine::Init() {
    L = luaL_newstate();
    luaL_openlibs(L);
    return true;
}

void ReEngine::LuaEngine::Update() {

}

void ReEngine::LuaEngine::UnInit() {
    lua_close(L);
}
