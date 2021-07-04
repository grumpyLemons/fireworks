#include "bullet.h"
#include "server.h"
#include "physics/bullet.h"
#include "graphics/bullet.h"

namespace Logic {
    Bullet::Bullet(Server &lServer, Physics::Bullet *pB, Graphics::Bullet *gB)
            : Entity(lServer), pBullet(pB), gBullet(gB) {}

    Bullet::~Bullet() = default;

    void Bullet::UpdateGraphics() {
        gBullet->SetExploded(pBullet->GetState());
        if (!pBullet->GetState()) {
            gBullet->SetBulletPosition(pBullet->GetCoordinates().first, pBullet->GetCoordinates().second);
        }
        else {
            int i = 0;
            for (auto &&splinter : pBullet->GetSplinters()) {
                gBullet->SetSplinterPos(i, splinter.GetCoordinates().first, splinter.GetCoordinates().second);
                i++;
            }
        }

    }

    void Bullet::OnFrame(float dt) {
        if (pBullet->GetSplintersState())
            lServer.RegisterEntityDelete(this);
        else
            UpdateGraphics();
    }
}
