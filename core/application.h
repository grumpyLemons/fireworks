#pragma once

#include "gameinterface.h"

class Application {
public:
    explicit Application(const GameInterface& interface);

    ~Application();

    void Open();

    [[noreturn]] void Run() const;

private:

    void HandleEvents() const;

    GameInterface gameInterface;
};