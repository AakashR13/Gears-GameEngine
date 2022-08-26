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

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in Client
	Application* CreateApplication();
}




