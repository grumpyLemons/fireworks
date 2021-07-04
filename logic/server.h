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

    class Server final : public Core::Server<Entity> {
    public:
        Server();

        ~Server();

        void RegisterEntityDelete(Entity *Entity);

    private:
        void onFrameImpl(float dt) override;
        std::vector<Entity *> deletedEntities;
    };
}
