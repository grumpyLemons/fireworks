#include "server.h"
#include <SFML/Graphics.hpp>
#include <chrono>

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
        window->display();

        auto&& start = std::chrono::high_resolution_clock::now();
        std::size_t elapsedTime{0};
        while (elapsedTime < activeTime)
        {
            sf::Event event{};
            if(window-> pollEvent(event)){
                if(event.type == sf::Event::EventType::KeyPressed){
                    if(event.key.code == sf::Keyboard::C){
                        buttons[unsigned(Input::Button::P_C)] = true;
                    }
                }
            }

            auto&& end = std::chrono::high_resolution_clock::now();
            elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
    }

    void Entity::OnFrame(float dt) {}
    void Server::OnFrameImpl(float dt) {}

}