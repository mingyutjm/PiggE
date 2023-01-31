#pragma once

#include "Core.h"

namespace PiggE {
    class PIGGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be define in CLIENT
    Application* CreateApplication();
}
