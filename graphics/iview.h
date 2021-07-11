#pragma once

namespace Graphics
{
    class IView
    {
    public:
        virtual ~IView() = default;

        virtual void BeforeRender() = 0;
        virtual void Render(std::size_t activeTime) = 0;

        virtual void Open() = 0;
        virtual void Close() = 0;

        virtual void SetParticlesCount(std::size_t count) = 0;
    };
}