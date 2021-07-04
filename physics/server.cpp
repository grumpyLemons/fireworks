#include "server.h"

namespace Physics {
    Entity::Entity(Server &server)
            : pServer(server) {
        pServer.registerEntity(this);
    }

    Entity::~Entity() {
        pServer.unregisterEntity(this);
    }

    void Entity::OnFrame(float dt) {}

    Server::Server() = default;

    Server::~Server() = default;
    void Server::onFrameImpl(float dt) {}
}