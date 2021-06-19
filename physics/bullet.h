#include "server.h"
#include <vector>

namespace Physics{
    float g = 9.8;
    class Splinter : public Entity{
    public:
        void Simulate(float dt);
    private:
        float velocityX, velocityY;
        float currentX, currentY;
    };

    class Bullet : public Entity{
    public:
        Bullet(Server& server): Entity(server) {};
        ~Bullet() = default;
        virtual void OnFrame(float dt);
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);
        void Velocity();
    private:
        std::vector<Splinter> splinters;
        float initialX, initialY, velocityY;
        float endY, currentY;

    };
}