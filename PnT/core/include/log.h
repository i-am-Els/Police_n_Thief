//
// Created by Eniola Olawale on 10/6/2023.
//

#pragma once

#include "core_macros.h"
#include <iostream>
#include <cstdarg>

namespace pnt {
    enum class LogLevel{
        Error = 0, Warning, Info
    };

    class PNT_API PLog {
    private:
        PLog();
        static std::string stringifyLogLevel(LogLevel x);
    public:
        static LogLevel level;
        [[nodiscard]] static PLog& getInstance();
        static void echoMessage(const char* message, LogLevel _level = LogLevel::Info);
        static void echoMessage(LogLevel _level = LogLevel::Info, const char* message = "", ...);

        template<class T>
         static void echoValue(T value){
            std::cout << "[Value] " << value << std::endl;
        }
        static void terminate();
        ~PLog();
    };

} // pnt


