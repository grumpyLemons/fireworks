#include "server.h"
#include <SFML/Graphics.hpp>
namespace Graphics {
    Entity::Entity(Server &server)
            : gServer(server) {
        gServer.registerEntity(this);
    }

    Entity::~Entity() {
        gServer.unregisterEntity(this);
    }

    Server::Server() = default;

    Server::~Server() = default;
    void Entity::OnFrame(float dt) {}
    void Server::onFrameImpl(float dt){}

}