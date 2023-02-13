#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "LayerStack.h"
//#include "Window.h"
//#include "PiggE/Events/ApplicationEvent.h"

namespace PiggE {
    class PIGGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(class Layer* layer);
        void PushOverlay(class Layer* layer);
    private:
        bool OnWindowClose(class WindowCloseEvent& e);
    private:
        std::unique_ptr<class Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // To be define in CLIENT
    Application* CreateApplication();
}