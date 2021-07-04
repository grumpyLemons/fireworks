#pragma once

#include "server.h"

namespace Logic {
    Entity::Entity(Server &server)
            : lServer(server) {
        lServer.registerEntity(this);
    }

    Entity::~Entity() {
        lServer.unregisterEntity(this);
    }

    Server::Server() {}

    Server::~Server() {}

    Server::RegisterEntityDelete(Entity *Entity) {
    deletedEntites.push_back(Entity);
}
}