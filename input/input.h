#pragma once

enum class Button{};

class Input
{
public:
    virtual void OnFrame() = 0;
    virtual bool IsPressed(Button button) = 0;
};