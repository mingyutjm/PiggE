#include "pigpch.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "Application.h"
#include "Window.h"
#include "PiggE/Log.h"
#include "PiggE/Events/ApplicationEvent.h"
#include "Layer.h"
#include "Input.h"

namespace PiggE {

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        PIG_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(PIG_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(PIG_BIND_EVENT_FN(Application::OnWindowClose));
        PIG_CORE_INFO("{0}", e);

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::PushLayer(class Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(class Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true; 
    }
}
