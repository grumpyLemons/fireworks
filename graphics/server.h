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

    class Server : public Core::Server<Entity> {
    public:
        Server();

        ~Server();

        void onFrameImpl(float dt) override;
    };
}

