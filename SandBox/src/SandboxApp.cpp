#include <Gears.h> 

class ExampleLayer : public Gears::Layer
{
public:
	ExampleLayer()
		: Layer()
	{
	}

	void OnUpdate() override
	{
		GR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Gears::Event & event) override
	{
		GR_TRACE("{0}",event);
	}
};

class Sandbox :public Gears::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Gears::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Gears::Application* Gears::CreateApplication()
{
	return new Sandbox();
}