#include "application.h"
#include "../graphics/graphics.h"
#include "../logic/logic.h"
#include "../input/input.h"
#include "../audio/audio.h"
#include "../ai/aimodule.h"

Application::Application(Audio* audio, Logic* logic, AiModule* aimodule, Graphics* graphics, Input* input){
    m_input = input;
    m_graphics = graphics;
    m_ai = aimodule;
    m_logic = logic;
    m_audio = audio;
}
bool Application::Activate() {return false;}
void Application::Run() {}
void Application::Deactivate() {}
