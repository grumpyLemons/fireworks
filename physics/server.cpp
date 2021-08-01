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

    Server::Server() {
        threadPool.run();
    }

    Server::~Server() {
        threadPool.stop();
    }
    void Server::AddJob(ThreadPool::Job&& task) {
        threadPool.add_job(std::move(task));
    }
    void Server::OnFrameImpl(float dt) {
        threadPool.wait();
    }
}