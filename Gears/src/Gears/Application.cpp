#include "Application.h"

#include "Gears/Events/ApplicationEvent.h"
#include "Gears/Log.h"

namespace Gears {

	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		GR_TRACE(e);

		while (true){};
	}
}