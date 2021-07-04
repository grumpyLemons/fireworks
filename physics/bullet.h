#include "server.h"
#include <vector>
#include <pair>

namespace Physics{
    float g = 9.8;
    class Splinter : public Entity{
    public:
        void Simulate(float dt);
        std::pair<float, float> GetCoordinates();
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
        bool GetState();
        bool GetSplintersState();
        std::pair<float,float> GetCoordinates();
        std::vector<Splinter> GetSplinters();
        void Velocity();
    private:
        std::vector<Splinter> splinters;
        float initialX, initialY, velocityY;
        float endY, currentY;
        bool isExploded = false;
        bool isOnGround = false;

    };
}