#pragma once

#include "PiggE/Core.h"

#include <vector>

namespace PiggE {

    class PIGGE_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(class Layer* layer);
        void PushOverlay(class Layer* layer);
        void PopLayer(class Layer* layer);
        void PopOverlay(class Layer* layer);

        std::vector<class Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<class Layer*>::iterator end() { return m_Layers.end(); }
    private:
        std::vector<class Layer*> m_Layers;
        std::vector<class Layer*>::iterator m_LayerInsert;
    };
}