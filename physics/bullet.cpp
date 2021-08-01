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
        if (coordinates.Y < endY) {
            coordinates.Y += velocityY * dt;
            velocityY -= g * dt;
        }
        else
            Explosion();
    }

    void Bullet::ProcessSplinter(float dt) {
        isOnGround = true;
        for (auto& splinter: splinters) {
            splinter.Simulate(dt);
            if (splinter.GetCoordinates().X > 0) {
                isOnGround = false;
            }
        }
    }

    void Bullet::Explosion() {
        for (std::size_t i{0}; i < 100 + (int)rand() % 10; ++i)
            {
                std::pair<float, float>  splinterVelocity;
                splinterVelocity.first = velocityY - 2 * (double)rand() / RAND_MAX * velocityY;

                const auto ySpeedMax = std::sqrt(velocityY * velocityY - splinterVelocity.first * splinterVelocity.first);
                splinterVelocity.second = ySpeedMax - 2 * (double)rand() / RAND_MAX * ySpeedMax;

                splinters.emplace_back(l_server, GetCoordinates(), splinterVelocity, pServer.GetWorldBox());
            }
        isExploded = true;
    }

    void Bullet::OnFrame(float dt) {
        if (!isExploded) {
            ProcessBullet(dt);
        }
        else {
            pServer.AddJob([dt, this] {ProcessSplinter(dt);});
        }
    }

    float Bullet::Velocity() const { return velocityY; }


    Splinter::Splinter(Server& Server, const Core::Vector3& position, const std::pair<float, float>& inp_velocity, const Box& serverWorldBox)
            : Entity(Server)
            , coordinates(position)
            , velocityX(inp_velocity.first)
            , velocityY(inp_velocity.second)
            , worldBox(serverWorldBox) {}

    bool Splinter::IsOnGround() const {
        return coordinates.Y <= 0;
    }

    void Splinter::Simulate(float dt) {
        if (IsOnGround())
            return;
        if (coordinates.Y <= worldBox.Y1 || coordinates.Y >= worldBox.Y2)
            velocityY *= -1;
        if (coordinates.X >= worldBox.X2 || coordinates.X <= worldBox.X1)
            velocityX *= -1;

        coordinates.Y += velocityY * dt;
        coordinates.X += velocityX * dt;
        velocityY -= g * dt;
    }

    bool Bullet::GetState() const { return isExploded; }

    const Core::Vector3& Bullet::GetCoordinates() const {
        return coordinates;
    }

    std::vector<Splinter>& Bullet::GetSplinters() { return splinters; }

    const Core::Vector3& Splinter::GetCoordinates() const { return coordinates; }


    bool Bullet::GetSplintersState() const { return isOnGround; }
}