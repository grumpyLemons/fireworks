#include "server.h"

namespace Graphics{
    class Bullet : public Entity{
    public:
        void OnFrame();
        void SetExploded(bool value) {isExploded = value; };
        void SetBulletPosition(float x, float y) {
            currentX = x;
            currentY = y;}
    private:
        float currentX;
        float currentY;
    };
}