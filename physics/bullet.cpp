#include <cstdlib>
#include "bullet.h"
namespace Physics{
    Bullet::Bullet(Server &pServer)
    : Entity(pServer){}
    void Bullet::ProcessBullet(float dt) {
        currentY += velocityY*dt;
        velocityY -= g*dt;
    }
    void Bullet::ProcessSplinter(float dt) {
        isOnGround = true;
        for(auto& splinter: splinters)
        {
            splinter.Simulate(dt);
            if (splinter.Y > 0)
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
    bool Bullet::GetState() {return isExploded;}
    std::pair<float, float> Bullet::GetCoordinates() { return (currentX, currentY);}
    std::vector<Splinter> Bullet::GetSplinters() { return splinters; }
    std::pair<float, float> Splinter::GetCoordinates() { return (currentX, currentY);}
    bool Bullet::GetSplintersState() { return isOnGround;}
}