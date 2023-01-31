
#include <PiggE.h>

class Sandbox : public PiggE::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

PiggE::Application* PiggE::CreateApplication()
{
    return new Sandbox();
}
