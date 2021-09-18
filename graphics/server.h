#pragma once

#include "core/server.h"
#include "input/iserver.h"
#include "iview.h"

#include <array>
#include <memory>

namespace sf {
    class RenderWindow;
    class Text;
    class Font;
    class Texture;
}

namespace Graphics {
    class Server;

    class Entity {
    public:
        explicit Entity(Server& server);

        ~Entity();
        virtual void OnFrame(float dt);

    protected:
        unsigned X, Y;
        Server& gServer;
    };

    class Server : public IView, public Core::Server<Entity>, public Input::IServer {
    public:
        Server();
        ~Server() override;

        void BeforeRender() override;
        void Render(std::size_t activeTime) override;

        void Open() override;
        void Close() override;

        void SetParticlesCount(std::size_t count) override { particles = count; };
        bool IsPressed(Input::Button button) const override;

        sf::RenderWindow& RenderWindow() const { return *window; }
        sf::Texture& BulletTexture() const { return *bulletTexture; }
        std::size_t GetHeight() const { return Height; }

        void OnFrameImpl(float dt) override;

    private:

        void CreateContext();
        void UpdateButtons();

        std::unique_ptr<sf::RenderWindow> window;
        std::unique_ptr<sf::Text> particlesCount;
        std::unique_ptr<sf::Font> font;
        std::unique_ptr<sf::Texture> bulletTexture;

        std::size_t particles = 0;

        std::array<bool, unsigned(Input::Button::Count)> buttons;

        static constexpr std::size_t Height{900};
        static constexpr std::size_t Width{900};
    };
}

