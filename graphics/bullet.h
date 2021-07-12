#pragma once

#include "server.h"
#include "core/vector.h"

namespace Graphics {
    class Bullet : public Entity {
    public:
        Bullet(Core::Vector3 position, Server& Server);

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