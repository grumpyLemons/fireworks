#include "server.h"

namespace Logic{
    class Splinter : public Entity {
    public:
        void Simulate(float dt);
    }
    class Bullet : public Entity{
    public:
        void OnFrame(float dt);
    };
}