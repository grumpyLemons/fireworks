#pragma once
#include "../core/server.h"

namespace Graphics
{
    class Server;
    class Entity {
        Entity(Server& server);
        ~Entity();
        virtual void OnFrame(float dt)
    };
    class Server {
    public:
        void OnFrameImpl(float dt);
    };
}

