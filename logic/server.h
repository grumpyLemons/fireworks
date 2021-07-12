#pragma once

#include "core/server.h"

namespace Physics
{
    class Server;
}

namespace Graphics
{

    class Server;

}

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
        Server(Graphics::Server& server, Physics::Server& server1);

        ~Server();

        void RegisterEntityDelete(Entity *Entity);

    private:
        Graphics::Server& graphics;
        Physics::Server& physics;
        void OnFrameImpl(float dt) override;
        std::vector<Entity *> deletedEntities;
    };
}
