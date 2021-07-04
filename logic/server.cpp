#include "server.h"

namespace Logic {
    Entity::Entity(Server &server)
            : lServer(server) {
        lServer.registerEntity(this);
    }

    Entity::~Entity() {
        lServer.unregisterEntity(this);
    }

    void Entity::OnFrame(float dt) {}
    Server::Server() = default;

    Server::~Server() = default;

    void Server::RegisterEntityDelete(Entity *Entity) {
    deletedEntities.push_back(Entity);
    }
    void Server::onFrameImpl(float dt) {
        for (auto* entity : deletedEntities)
        {
            delete entity;
        }
        deletedEntities.clear();
    }
}