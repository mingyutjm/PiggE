#pragma once

#ifdef PIG_PLATFORM_WINDOWS

extern PiggE::Application* PiggE::CreateApplication();

int main(int argc, char** argv)
{
    PiggE::Log::Init();
    PIG_CORE_WARN("Init Log!");
    int a = 7;
    PIG_INFO("Init Log ! Var={0}", a);

    printf("PiggE Engine");
    auto app = PiggE::CreateApplication();
    app->Run();
    delete app;
}

#endif // PIG_PLATFORM_WINDOWS

