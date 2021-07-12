#pragma once

#include "server.h"
#include "core/vector.h"
#include "SFML/Graphics.hpp"

namespace sf
{
    class Texture;
    class Sprite;
}

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

        sf::Texture& texture;
        std::unique_ptr<sf::Sprite> sprite;


        float currentX;
        float currentY;
        bool isExploded = false;

        struct Position final {
            float X;
            float Y;

            Position(float x, float y)
            : X(x)
            , Y(y) {}
        };

        std::vector<Position> splinters;
    };
}