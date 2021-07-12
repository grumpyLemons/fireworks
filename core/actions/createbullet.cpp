#include "createbullet.h"
#include "physics/bullet.h"
#include "logic/bullet.h"
#include "graphics/bullet.h"
#include "core/vector.h"

namespace Action {
    void CreateBullet::Execute() const {
        Core::Vector3 position;
        position.X = (double) rand() / RAND_MAX * 500;
        position.Y = 30;
        position.Z = 0;

        auto* physics = new Physics::Bullet(position, *interface.pServer);
        auto* graphics = new Graphics::Bullet(position, *interface.gServer);
        auto* logic = new Logic::Bullet(*interface.lServer, physics, graphics);
    }

    CreateBullet::CreateBullet(const GameInterface& iface)
            : interface(iface) {}

}
