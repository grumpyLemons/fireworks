#include "bullet.h"
#

namespace Graphics {
    Bullet::Bullet(Core::Vector3 position, Server& pServer) : Entity(pServer) {
        SetBulletPosition(position.X, position.Y);
    }

    Bullet::~Bullet() = default;

    void Bullet::OnFrame(float dt) {
        if (isExploded) {
            for (int i = 0; i < splinters.size(); i++) {
                SetSplinterPos(i, currentX, currentY);
            }
        }
    }

    void Bullet::SetSplinterPos(int index, float x, float y) {
        if (splinters.size() > index) {
            splinters[index].x = x;
            splinters[index].y = y;
        } else {
            splinters.emplace_back(x, y);
        }
    }

    void Bullet::SetExploded(bool value) {
        isExploded = value;
    }

    void Bullet::SetBulletPosition(float x, float y) {
        currentX = x;
        currentY = y;
    }
}