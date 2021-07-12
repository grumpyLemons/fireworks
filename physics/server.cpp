#include "server.h"

namespace Physics {
    Entity::Entity(Server &server)
            : pServer(server) {
        pServer.RegisterEntity(this);
    }

    Entity::~Entity() {
        pServer.UnregisterEntity(this);
    }

    void Entity::OnFrame(float dt) {}

    Server::Server() = default;

    Server::~Server() = default;
    void Server::OnFrameImpl(float dt) {}
}