#include "core/application.h"
#include "core/gameinterface.h"
#include "graphics/server.h"
#include "physics/server.h"
#include "logic/server.h"

int main() {
    GameInterface interface;
    auto* physServer = new Physics::Server;
    auto* grphServer = new Graphics::Server;

    interface.lServer = new Logic::Server(*grphServer, *physServer);
    interface.pServer = physServer;
    interface.gServer = grphServer;

    Application application(interface);
    application.Open();
    application.Run();

    return 0;
}