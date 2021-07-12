#pragma once

namespace Action{
    class IAction{
    public:
        IAction() = default;
        virtual ~IAction() = default;

        virtual void Execute() const = 0;
    };
}