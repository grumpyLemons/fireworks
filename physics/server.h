#pragma once

#include "core/server.h"

namespace Physics {
    class Server;

    class Entity {
    public:
        Entity(Server &server);

        ~Entity();

        virtual void OnFrame(float dt);
    protected:
        Server &pServer;
    };

    class Server : public Core::Server<Entity> {
    public:
        Server();

        ~Server();

        void OnFrameImpl(float dt) override;
    };
}
