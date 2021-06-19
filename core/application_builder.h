#pragma once

class Audio;
class Input;
class AiModule;
class Graphics;
class Logic;
class Application;

class ApplicationBuilder
{
public:
    ApplicationBuilder& AddAi(AiModule* ai);
    ApplicationBuilder& AddAudio(Audio* audio);
    ApplicationBuilder& AddGraphics(Graphics* graphics);
    ApplicationBuilder& AddInput(Input* input);
    ApplicationBuilder& AddLogic(Logic* logic);
    ApplicationBuilder Create();
    Application Get();
private:
    ApplicationBuilder();
};
