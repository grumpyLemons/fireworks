#include "server.h"

namespace Physics {
    Entity::Entity(Server &server)
            : pServer(server) {
        pServer.registerEntity(this);
    }

    Entity::~Entity() {
        pServer.unregisterEntity(this);
    }

    Server::Server() {}

    Server::~Server() {}

}