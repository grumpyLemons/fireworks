#include <graphics/server.h>
#include <physics/server.h>
#include "server.h"

namespace Logic {
    Entity::Entity(Server &server)
            : lServer(server) {
        lServer.RegisterEntity(this);
    }

    Entity::~Entity() {
        lServer.UnregisterEntity(this);
    }

    void Entity::OnFrame(float dt) {}
    Server::Server(Graphics::Server& server, Physics::Server& server1)
    : graphics(server)
    , physics(server1)
    {}

    Server::~Server() = default;

    void Server::RegisterEntityDelete(Entity *Entity) {
    deletedEntities.push_back(Entity);
    }
    void Server::OnFrameImpl(float dt) {
        for (auto* entity : deletedEntities)
        {
            delete entity;
        }
        deletedEntities.clear();
    }
}