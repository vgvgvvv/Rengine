//
// Created by ¶­å· on 2018/5/1.
//

#ifndef RENGINE_LUAENGINE_HPP
#define RENGINE_LUAENGINE_HPP

#include <Systems/System.hpp>
#include <Lua/lua.h>

namespace ReEngine{
    class LuaEngine : public System{
    public:
        const lua_State* GetLuaState();
        bool Init() override;
        void Update() override;
        void UnInit() override;

    private:
        lua_State* L;
    };
}



#endif //RENGINE_LUAENGINE_HPP
