#pragma once

#include "server.h"

namespace Graphics {
    class Bullet : public Entity {
    public:
        Bullet(Server& Server, float x, float y);

        ~Bullet();

        void OnFrame(float dt);

        void SetSplinterPos(int index, float x, float y);

        void SetExploded(bool value);

        void SetBulletPosition(float x, float y);

    private:
        float currentX;
        float currentY;
        bool isExploded = false;
        struct Position final {
            float x;
            float y;
        };
        std::vector<Position> splinters;
    };
}