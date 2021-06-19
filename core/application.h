#pragma once

class Audio;
class Input;
class AiModule;
class Graphics;
class Logic;


class Application
{
public:
    bool Activate();
    void Run();
    void Deactivate();

private:
    Application(Audio*, Logic*, AiModule*, Graphics*, Input*);
    Audio* m_audio;
    Logic* m_logic;
    AiModule* m_ai;
    Graphics* m_graphics;
    Input* m_input;
};