#include <cstdlib>
#include "bullet.h"
#include <utility>

namespace Physics{
    void Bullet::ProcessBullet(float dt) {
        currentY += velocityY*dt;
        velocityY -= g*dt;
    }
    void Bullet::ProcessSplinter(float dt) {
        isOnGround = true;
        for(auto& splinter: splinters)
        {
            splinter.Simulate(dt);
            if (splinter.GetCoordinates().first > 0)
            {
                isOnGround = false;
            }
        }
    }
    void Bullet::OnFrame(float dt) {
        if(currentY < endY)
        {
            ProcessBullet(dt);
        }
        else
        {
            ProcessSplinter(dt);
        }
    }
    float Bullet::Velocity() {return velocityY;}
    void Splinter::Simulate(float dt) {
        currentY += velocityY*dt;
        currentX += velocityX*dt;
        velocityY -= g*dt;
    }
    bool Bullet::GetState() const {return isExploded;}
    std::pair<float, float> Bullet::GetCoordinates() { return std::make_pair(currentX, currentY);}
    std::vector<Splinter> Bullet::GetSplinters() { return splinters; }
    std::pair<float, float> Splinter::GetCoordinates() { return std::make_pair(currentX, currentY);}
    bool Bullet::GetSplintersState() const { return isOnGround;}
}