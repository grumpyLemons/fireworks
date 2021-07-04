#include "server.h"

namespace Graphics {
    Entity::Entity(Server &server)
            : gServer(server) {
        gServer.registerEntity(this);
    }

    Entity::~Entity() {
        gServer.unregisterEntity(this);
    }

    Server::Server() {}

    Server::~Server() {}

}