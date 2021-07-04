#include <cstdlib>
#include "bullet.h"
namespace Physics{
    Bullet::Bullet(Server &server) {}
    void Bullet::ProcessBullet(float dt) {
        currentY += velocityY*dt;
        velocityY -= g*dt;
    }
    void Bullet::ProcessSplinter(float dt) {
        for(Splinter* splinter: splinters)
        {
            splinter.simulate();
        }
        Bullet::isOnGround = true;
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