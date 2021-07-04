#pragma once
#include "server.h"
#include <vector>

namespace Graphics{
    class Bullet;
}

namespace Physics{
    class Bullet;
}

namespace Logic{
    class Bullet : public Entity{
    public:
        Bullet(Server& lServer, Physics::Bullet* pB, Graphics::Bullet* gB);
        ~Bullet();
        void UpdateGraphics();
        void OnFrame(float dt) override;

    private:
        Physics::Bullet* pBullet;
        Graphics::Bullet* gBullet;
    };
}
