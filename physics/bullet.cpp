#include <cstdlib>
#include "bullet.h"
#include <utility>
#include <cmath>

namespace Physics {
    Bullet::Bullet(Core::Vector3& position, Server& server, float inp_velocity, float endHeight)
        : Entity(server)
        , coordinates(position)
        , endY(endHeight)
        , velocityY(inp_velocity)
        , l_server(server){}

    Bullet::~Bullet() = default;

    void Bullet::ProcessBullet(float dt) {
        coordinates.Y += velocityY * dt;
        velocityY -= g * dt;
    }

    void Bullet::ProcessSplinter(float dt) {
        isOnGround = true;
        for (auto& splinter: splinters) {
            splinter.Simulate(dt);
            if (splinter.GetCoordinates().first > 0) {
                isOnGround = false;
            }
        }
    }

    void Bullet::Explosion() {
        for (std::size_t i{0}; i < 10 + (int)rand() % 10; ++i)
            {
                std::pair<float, float>  splinterVelocity;
                splinterVelocity.first = velocityY - 2 * (double)rand() / RAND_MAX * velocityY;

                const auto ySpeedMax = std::sqrt(velocityY * velocityY - splinterVelocity.first * splinterVelocity.first);
                splinterVelocity.second = ySpeedMax - 2 * (double)rand() / RAND_MAX * ySpeedMax;

                splinters.emplace_back(l_server, GetCoordinates(), splinterVelocity);
            }
    }

    void Bullet::OnFrame(float dt) {
        if (coordinates.Y < endY) {
            ProcessBullet(dt);
        }
        else if (!isExploded) {
            isExploded = true;
            Explosion();
        }
        else {
            ProcessSplinter(dt);
        }
    }

    float Bullet::Velocity() const { return velocityY; }


    Splinter::Splinter(Server& Server, Core::Vector3& position, std::pair<float, float> inp_velocity)
            : Entity(Server)
            , currentY(position.Y)
            , currentX(position.X)
            , velocityX(inp_velocity.first)
            , velocityY(inp_velocity.second) {}

    void Splinter::Simulate(float dt) {
        currentY += velocityY * dt;
        currentX += velocityX * dt;
        velocityY -= g * dt;
    }

    bool Bullet::GetState() const { return isExploded; }

    Core::Vector3& Bullet::GetCoordinates() {
        return coordinates;
    }

    std::vector<Splinter> Bullet::GetSplinters() { return splinters; }

    std::pair<float, float> Splinter::GetCoordinates() { return std::make_pair(currentX, currentY); }


    bool Bullet::GetSplintersState() const { return isOnGround; }
}