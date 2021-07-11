#pragma once

class Input;
class Graphics;
class Logic;
class Application;
class Physics;

class ApplicationBuilder
{
public:
    ApplicationBuilder& AddPhysics(Physics*);
    ApplicationBuilder& AddGraphics(Graphics*);
    ApplicationBuilder& AddInput(Input*);
    ApplicationBuilder& AddLogic(Logic*);
    ApplicationBuilder Create();
    Application Get();
private:
    ApplicationBuilder();
};
