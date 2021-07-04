#pragma once

#include "core/server.h"

namespace Graphics {
    class Server;

    class Entity {
    public:
        Entity(Server &server);

        ~Entity();

        virtual void OnFrame(float dt);

    protected:
        Server &gServer;
    };

    class Server : public Core::Server {
    public:
        Server();

        ~Server();

        void OnFrameImpl(float dt);
    };
}

