#include "server.h"
#include <SFML/Graphics.hpp>

namespace Graphics {
    Entity::Entity(Server& server)
            : gServer(server) {
        gServer.RegisterEntity(this);
    }

    Entity::~Entity() {
        gServer.UnregisterEntity(this);
    }

    Server::Server() {
        buttons.fill(false);
    }

    Server::~Server() {
        Close();
    }

    void Server::Open() {
        CreateContext();
        Render(10);
    }

    void Server::Close() {}

    bool Server::IsPressed(Input::Button button) const {
        return buttons[unsigned(button)];
    }

    void Server::CreateContext() {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Width, Height), "Fireworks test",
                                                    sf::Style::Titlebar | sf::Style::Close);

        window->setVerticalSyncEnabled(true);

        font = std::make_unique<sf::Font>();
        font->loadFromFile("../resources/LiberationSans-Regular.ttf");

        particlesCount = std::make_unique<sf::Text>("Particles Count", *font, 20);
        particlesCount->setPosition(80, 865);
        particlesCount->setFillColor(sf::Color(0, 0, 0));

        bulletTexture = std::make_unique<sf::Texture>();
        bulletTexture->loadFromFile("../resources/bullet.png");

    }

    void Server::UpdateButtons() {
        buttons[unsigned(Input::Button::P_C)] = sf::Keyboard::isKeyPressed(sf::Keyboard::C);
    }

    void Server::BeforeRender() {
        window->clear(sf::Color(255, 255, 255));
        buttons.fill(false);
    }

    void Server::Render(std::size_t activeTime) {
        particlesCount->setString("Particles Count: " + std::to_string(particles));
        window->draw(*particlesCount);

        window->display();

        sf::Event Event{};

    }

    void Entity::OnFrame(float dt) {}
    void Server::OnFrameImpl(float dt) {}

}