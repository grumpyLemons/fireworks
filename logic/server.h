#pragma once

#include "core/server.h"

namespace Logic {
    class Server;

    class Entity {
    public:
        Entity(Server &server);

        ~Entity();

        virtual void OnFrame(float dt);
    protected:
        Server &lServer;
    };

    class Server final : public Core::Server {
    public:
        Server();

        ~Server();

        void RegisterEntityDelete(Entity *Entity);

    private:
        virtual void OnFrameImpl(float dt) override {};
        std::vector<Entity *> deletedEntities;
    };
}
