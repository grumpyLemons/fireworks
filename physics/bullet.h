#include "server.h"
#include <vector>

namespace Physics {
    class Splinter : public Entity {
    public:
        void Simulate(float dt);
        std::pair<float, float> GetCoordinates();

    private:
        float g = 9.8;
        float velocityX, velocityY;
        float currentX, currentY;
    };

    class Bullet : public Entity {
    public:
        Bullet(Server& server)
                : Entity(server) {};
        ~Bullet() = default;

        void OnFrame(float dt) override;
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);

        bool GetState() const;
        bool GetSplintersState() const;

        std::pair<float, float> GetCoordinates();
        std::vector<Splinter> GetSplinters();

        float Velocity();

    private:
        float g = 9.8;
        std::vector<Splinter> splinters;
        float initialX, initialY, velocityY;
        float endY, currentY, currentX;
        bool isExploded = false;
        bool isOnGround = false;

    };
}