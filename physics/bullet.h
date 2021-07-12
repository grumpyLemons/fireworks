#include "server.h"
#include "core/vector.h"
#include <vector>

namespace Physics {
    class Splinter : public Entity {
    public:
        Splinter(Server& Server, Core::Vector3& position, std::pair<float, float> inp_velocity);
        ~Splinter() = default;
        void Simulate(float dt);
        std::pair<float, float> GetCoordinates();

    private:
        float g = 9.8;
        float velocityX, velocityY;
        float currentX, currentY;
    };

    class Bullet : public Entity {
    public:
        Bullet(Core::Vector3& position, Server& server, float inp_velocity = 1, float endHeight = 512);
        ~Bullet() = default;

        void OnFrame(float dt) override;
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);

        bool GetState() const;
        bool GetSplintersState() const;

        std::pair<float, float> GetCoordinates();
        std::vector<Splinter> GetSplinters();

        float Velocity() const;

    private:
        float g = 9.8;
        std::vector<Splinter> splinters;
        float initialX, initialY, velocityY;
        float endY, currentY, currentX;
        bool isExploded = false;
        bool isOnGround = false;

    };
}