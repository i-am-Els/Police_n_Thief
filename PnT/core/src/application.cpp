//
// Created by Eniola Olawale on 9/17/2023.
//


/* *************************************************************************************
 *                                 Police and Thief Game
 * *************************************************************************************
 *
 * Two entities, Yourself and the AI.
 * Roles: 1. Police - Find the Thief.
 *        2. Thief - Avoid apprehension.
 *
 * Role switches at the beginning based on aa coin toss.
 * Outcomes:
 *      Police - Head
 *      Thief - Tail
 *
 * Actions:
 *      WASD movement
 *      Shooting
 *
 * Winning:
 * The winners is the last man standing.
 *
 * *************************************************************************************
*/

/*
 * AI - State Machine
 *    - Pathfinding (A* algorithm, Greedy Best First or Dijkstra)
 * PInput Handling
 * Rendering -
 *      Abstraction
 *      Text Rendering
 *      HUD - In game GUI (Buttons, Labels, CheckBoxes, RadioButtons, InputArea, ToggleButton, Slider, Panels, Frames
 *               GridLayout, BoxLayout(s), StackLayout, Widgets),
 *               Health Bar, Character Attributes and in game layout
 * Sound manager
 * Asset manager
 *
 * */

#include <iostream>

#include "application.h"
#include "entity.h"
#include "input.h"
#include "render_system_conc.h"
#include "ecs_service_conc.h"

using namespace isle_engine::math;
using namespace pnt::ecs;

namespace pnt{
    PApplication *CreateApplication();
}

int main(){
    pnt::PApplication* application = pnt::CreateApplication();

    application->init();
    application->start();  // TODO - HACK added
    while(!application->window->windowClose())
    {
        // Poll PInput
        application->process();
        // update State
        application->update(1.f);
        // render Scene
        application->render();
    }
    application->destroy();
    // TODO - [Optionally] Make use of a defined game state monitor
    application->exit();

    delete application;
    return 0;
}

// TODO Implement PCameraComponent
// TODO Introduce transformations
// TODO Rendering textures and more shader abstractions

namespace pnt{

    void PApplication::process() {
        // Call the process method on all the services
        serviceLocator->getService<IECSService>()->process();
        PInput::PollEvents();
    }

    void PApplication::update(float deltaTime) {
        // Call the update method on all the services
        serviceLocator->getService<IECSService>()->update(1.0f);
    }

    void PApplication::render() {
        // Call the render method on all the services
        serviceLocator->getService<IECSService>()->render();
    }

    void PApplication::init() {
        // Set up window
        PWindow::bindWindowBackendAPI();
        window = PWindow::createWindow(applicationInfo.width, applicationInfo.height, applicationInfo.title.c_str());

        // Create all Services
        auto ecsService = std::make_shared<PECSService>(window.get());

        // Register Services
        serviceLocator->registerService<IECSService>(ecsService);

        // Call the init method on all the services
        serviceLocator->getService<IECSService>()->init();

    }

    void PApplication::destroy() {
        // Call the destroy method on all the services

        serviceLocator->getService<IECSService>()->destroy();
    }

    void PApplication::exit() {
        // nothing for now
        PWindow::unbind();
    }

    void PApplication::start() {
#ifdef HACK_
        dynamic_cast<PECSService*>(serviceLocator->getService<IECSService>().get())->start();
#endif //HACK_
    }
}
