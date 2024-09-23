//
// Created by Eniola Olawale on 6/18/2024.
//

#pragma once

#include "pnt_core_pch.h"
#include "service_locator.h"
#include "window_pnt.h"
#include "scene.h"

using namespace pnt::graphics;
namespace pnt{

    class PNT_API PApplication {
    protected:
        PApplication(const std::string &title, int width, int height)
        : applicationInfo(ApplicationInfo{title, width, height}), serviceLocator(std::make_shared<PServiceLocator>()) {
        }

    public:
        std::unique_ptr<PWindow> window;
        virtual ~PApplication() = default;
        virtual void init();
        virtual void start();
        virtual void process();
        virtual void update(float deltaTime);
        virtual void render();
        virtual void destroy();
        virtual void exit();

        std::shared_ptr<PServiceLocator> serviceLocator;
        PScene Scene{};

        struct PNT_API ApplicationInfo{
            const std::string &title;
            int width;
            int height;
        } applicationInfo;
    };

    // To be defined in client code
    PNT_API PApplication* CreateApplication();
}