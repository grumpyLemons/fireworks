#pragma once

namespace Input {
    enum class Button : uint8_t
    {
        P_C = 0,
        Count,
    };

    class IServer {
    public:
        IServer() = default;
        virtual ~IServer() = default;

        virtual bool IsPressed(Button button) const = 0;
    };
}