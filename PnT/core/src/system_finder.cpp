//
// Created by Eniola Olawale on 9/7/2024.
//

#include "system_finder.h"
#include "application.h"
#include "service_locator.h"
#include "ecs_service_conc.h"

namespace pnt{
    PApplication* PSystemFinder::application = nullptr;

    PApplication *PSystemFinder::GetApplication() {
        return application;
    }

    PECSService *PSystemFinder::PGetECSService() {
        return dynamic_cast<PECSService *>(application->serviceLocator->getService<IECSService>().get());
    }

    std::shared_ptr<PServiceLocator> PSystemFinder::GetServiceLocator() {
        return application->serviceLocator;
    }
}