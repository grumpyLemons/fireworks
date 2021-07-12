#include "application.h"

#include <chrono>

#include "physics/server.h"
#include "graphics/server.h"
#include "logic/server.h"

namespace {
    constexpr std::size_t FrameTime{16};
}

Application::Application(const GameInterface& interface)
        : gameInterface(interface) {}

Application::~Application() {}

void Application::Open() {
    gameInterface.gServer->Open();
}

void Application::Run() const {}