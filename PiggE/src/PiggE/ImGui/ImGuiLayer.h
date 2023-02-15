#pragma once

#include "PiggE/Layer.h"

#include "PiggE/Events/Event.h"
#include "PiggE/Events/ApplicationEvent.h"
#include "PiggE/Events/MouseEvent.h"
#include "PiggE/Events/KeyEvent.h"

namespace PiggE {

    class PIGGE_API ImGuiLayer : public Layer 
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        // Mouse events
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        // Key events
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        // Window events
        bool OnWindowResizedEvent(WindowResizeEvent& e);
    private:
        float m_Time = 0.0f;
    };

}