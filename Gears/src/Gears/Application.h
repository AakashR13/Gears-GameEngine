#pragma once

#include "Core.h"

#include "Window.h"
#include "Gears/LayerStack.h"
#include "Gears/Events/Event.h"
#include "Gears/Events/ApplicationEvent.h"


namespace Gears {

	class GEARS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in Client
	Application* CreateApplication();
}




