#pragma once

#ifdef GR_PLATFORM_WINDOWS

extern Gears::Application* Gears::CreateApplication();

int main(int argc, char** argv)
{
	printf("Gears Engine starts here!\n");
	auto app = Gears::CreateApplication();
	app->Run();
	delete app;
}

#endif // GR_PLATFORM_WINDOWS
