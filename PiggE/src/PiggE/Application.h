#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "LayerStack.h"
//#include "Window.h"
//#include "PiggE/Events/ApplicationEvent.h"


namespace PiggE {
    class Layer;
    class Window;
    class WindowCloseEvent;

    class PIGGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;
    };

    // To be define in CLIENT
    Application* CreateApplication();
}