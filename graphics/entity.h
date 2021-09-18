#include "server.h"
namespace Graphics {
    class Solid : public Entity {
        Solid(unsigned X, unsigned Y, Server& Server);
        ~Solid();
    };
    class Animated : public Entity {
    public:
        Animated(unsigned X, unsigned Y, Server& Server);
        ~Animated();
    protected:
        double stage;
    private:
        void ComputeStage(double dt);
    };
    class Pacman : public Animated {
    public:
        using Animated::Animated;
        void SetAlpha(bool state);
    private:
        bool isAlpha = false;
    };
    class Ghost : public Animated {
    public:
        using Animated::Animated;
        void SetFleeing(bool state);
        void ProcessFleeing(double dt);
    private:
        bool isScared;
    };
}