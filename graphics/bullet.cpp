#include "bullet.h"

namespace Graphics
{
    Bullet::Bullet(Server& pServer, float x, float y)
    : Entity(pServer){
        SetBulletPosition(x, y)
    }
    Bullet::~Bullet(){}
    void Bullet::OnFrame(float dt){
        if (isExploded)
        {
            for (int i; i < splinters.size(); i++)
            {
                SetSplinterPos(i, currentX, currentY);
            }
        }
    }
    void Bullet::SetSplinterPos(int index, float x, float y)
    {
        if (splinters.size() > index) {
            splinters[index].x = x;
            splinters[index].y = y;
        } else {
            splinters.mplace_back(x, y);
        }
    }
    void Bullet::SetExploded(bool value){
        isExploded = value;
    }
    void Bullet::SetBulletPosition(float x, float y)
    {
        currentX = x;
        currentY = y;
    }
}