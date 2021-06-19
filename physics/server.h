#include "../core/server.h"

namespace Physics{
    class Server;

    class Entity{
    public:
        Entity(Server& server);
        ~Entity();
        virtual void OnFrame(float dt){};
    };

    class Server : public core::Server{
    public:
        virtual void OnFrameImpl(float dt) override {};
    };
}