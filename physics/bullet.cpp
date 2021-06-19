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
    }
    void Bullet::OnFrame(float dt) {
        while(currentY < endY)
        {
            ProcessBullet(dt);
        }
        ProcessSplinter(dt);
    }
    float Bullet::Velocity() {return velocityY;}
    void Splinter::Simulate(float dt) {
        currentY += velocityY*dt;
        currentX += velocityX*dt;
        velocityY -= g*dt;
    }
}