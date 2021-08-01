#pragma once

#include "core/server.h"

namespace Physics {

    struct Box final
    {
        float X1{ 0.f };
        float Y1{ 0.f };

        float X2 { 0.f };
        float Y2 { 0.f };
    };

    class Server;

    class Entity {
    public:
        Entity(Server &server);

        ~Entity();

        virtual void OnFrame(float dt);
    protected:
        Server &pServer;
    };

    class Server : public Core::Server<Entity> {
    public:
        Server();

        ~Server();

        void OnFrameImpl(float dt) override;
        const Box& GetWorldBox() const { return worldBox; }
    private:
        constexpr static Box worldBox{ 0, 0, 800, 800 };
    };
}
