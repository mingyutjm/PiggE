#pragma once

#ifdef PIG_PLATFORM_WINDOWS

extern PiggE::Application* PiggE::CreateApplication();

int main(int argc, char** argv)
{
    printf("PiggE Engine");
    auto app = PiggE::CreateApplication();
    app->Run();
    delete app;
}

#endif // PIG_PLATFORM_WINDOWS

