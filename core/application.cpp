#include "application.h"

#include <chrono>

#include "actions/createbullet.h"
#include "physics/server.h"
#include "graphics/server.h"
#include "logic/server.h"
#include "input/iserver.h"

namespace {
    constexpr std::size_t FrameTime{16};
}

Application::Application(const GameInterface& interface)
        : gameInterface(interface) {}

Application::~Application() {}

void Application::Open() {
    gameInterface.gServer->Open();
}

void Application::Run() const {
    for (;;) {
        auto&& start = std::chrono::high_resolution_clock::now();

        HandleEvents();
        constexpr float FrameTimeSec{float(FrameTime) / 1000};
        gameInterface.pServer->OnFrame(FrameTimeSec);
        gameInterface.lServer->OnFrame(FrameTimeSec);

        gameInterface.gServer->BeforeRender();
        gameInterface.gServer->OnFrame(FrameTimeSec);

        auto&& end = std::chrono::high_resolution_clock::now();
        auto&& delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        gameInterface.gServer->Render(FrameTime - delta);
    }
    gameInterface.gServer->Close();
}

void Application::HandleEvents() const {
    if (gameInterface.gServer->IsPressed(Input::Button::P_C)) {
        const Action::CreateBullet bullet(gameInterface);
        bullet.Execute();
    }
}