
#include <PiggE.h>

class ExampleLayer : public PiggE::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        PIG_INFO("ExampleLayer::Update");
    }

    void OnEvent(PiggE::Event& event) override
    {
        PIG_INFO("{0}", event);
    }
};

class Sandbox : public PiggE::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

PiggE::Application* PiggE::CreateApplication()
{
    return new Sandbox();
}
