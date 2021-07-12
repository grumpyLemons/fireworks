#pragma once

namespace Graphics {

    class Server;

}

namespace Physics {

    class Server;

}

namespace Logic {

    class Server;

}


struct GameInterface {

    Physics::Server* pServer{nullptr};
    Logic::Server* lServer{nullptr};
    Graphics::Server* gServer{nullptr};
};