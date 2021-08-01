#include "server.h"
#include "core/vector.h"
#include <vector>

namespace Physics {
    class Splinter : public Entity {
    public:
        Splinter(Server& Server, const Core::Vector3& position, const std::pair<float, float>& inp_velocity, const Box& serverWorldBox);
        ~Splinter() = default;
        void Simulate(float dt);
        const Core::Vector3& GetCoordinates() const;

    private:
        bool IsOnGround() const;
        Box worldBox;
        float g = 9.8;
        float velocityX, velocityY;
        Core::Vector3 coordinates;
    };

    class Bullet : public Entity {
    public:
        Bullet(Core::Vector3& position, Server& server, float inp_velocity = 300, float endHeight = 512);
        ~Bullet();

        void OnFrame(float dt) override;
        void ProcessBullet(float dt);
        void ProcessSplinter(float dt);
        void Explosion();

        bool GetState() const;
        bool GetSplintersState() const;

        const Core::Vector3& GetCoordinates() const;
        std::vector<Splinter>& GetSplinters();

        float Velocity() const;

    private:
        Core::Vector3 coordinates;
        Server& l_server;
        float g = 9.8;
        std::vector<Splinter> splinters;
        float velocityY;
        float endY;
        bool isExploded = false;
        bool isOnGround = false;

    };
}