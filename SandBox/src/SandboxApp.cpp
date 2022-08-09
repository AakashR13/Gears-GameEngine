
#include <Gears.h> 

class Sandbox :public Gears::Application
{
public:
	Sandbox()
		 {

	}
	~Sandbox()
	{

	}
};

Gears::Application* Gears::CreateApplication()
{
	return new Sandbox();
}