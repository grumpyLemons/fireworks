#include "bullet.h"

namespace Graphics {
    Bullet::Bullet(Core::Vector3 position, Server& pServer) : Entity(pServer), texture(pServer.BulletTexture()) {
        SetBulletPosition(position.X, position.Y);
        sprite = std::make_unique<sf::Sprite>();

        sprite->setTexture(texture, true);
        sprite->setPosition(position.X, position.Y);
    }

    Bullet::~Bullet() = default;

    void Bullet::OnFrame(float dt) {
        if (isExploded) {
            sf::CircleShape circle;
            circle.setRadius(5);
            circle.setOutlineColor(sf::Color::Red);
            circle.setOutlineThickness(1);
            std::size_t i{0};
            for(auto&& splinter : splinters)
            {
                circle.setPosition(splinter.X, gServer.GetHeight() - splinter.Y);
                gServer.RenderWindow().draw(circle);
                SetSplinterPos(i, currentX, currentY);
                ++i;
            }
        }
        else
        {
            sprite->setPosition(currentX, gServer.GetHeight() - currentY);
            gServer.RenderWindow().draw(*sprite);
        }
    }

    void Bullet::SetSplinterPos(int index, float x, float y) {
        if (splinters.size() > index) {
            splinters[index].X = x;
            splinters[index].Y = y;
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