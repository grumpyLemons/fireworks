#include "../core/server.h"

namespace Logic{
    class Server;
    class Entity{
    public:
        Entity(Server& server);
        ~Entity();
        virtual void OnFrame(float dt)
    };

    class Server{
    public:
        void OnFrameImpl(float dt){};
    };
}