#include "server.h"

namespace Graphics{
    class Splinter : public Entity {
    public:
        void Simulate(float dt);
    }
    class Bullet : public Entity{
    public:
        void OnFrame();
    };
}