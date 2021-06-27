#include "../core/server.h"

namespace Logic{
    class Server;
    class Entity{
    public:
        Entity(Server& server);
        ~Entity();
        virtual void OnFrame(float dt);
    private:
        Server& server;
    };

    class Server : Core::Server<Entity>{
    public:
        void OnFrameImpl(float dt){};
    };
}
