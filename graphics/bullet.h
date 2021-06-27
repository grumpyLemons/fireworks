#include "server.h"

namespace Graphics{
    class Bullet : public Entity{
    public:
        void OnFrame();
        void SetSplinterPos(int index, float x, float y)
        {
            if (splinters.size() > index){
                splinters[index].x = x;
                splinters[index].y = y;
            }
            else
            {splinters.mplace_back(x, y);
            }

        };
        void SetExploded(bool value) {isExploded = value; };
        void SetBulletPosition(float x, float y) {
            currentX = x;
            currentY = y;}
    private:
        float currentX;
        float currentY;
        struct Position final
        {
            float x;
            float y;
        };
        std::vector<Position> splinters;
    };
}