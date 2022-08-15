#pragma once

#ifdef GR_PLATFORM_WINDOWS

extern Gears::Application* Gears::CreateApplication();

int main(int argc, char** argv)
{
	Gears::Log::Init();
	GR_CORE_WARN("Initialized Log!");
	GR_INFO("Yo log!");
	
	printf("Gears Engine starts here!\n");
	auto app = Gears::CreateApplication();
	app->Run();
	delete app;
}

#endif // GR_PLATFORM_WINDOWS

