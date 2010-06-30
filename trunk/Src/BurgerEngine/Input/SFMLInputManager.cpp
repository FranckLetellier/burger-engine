#include "SFMLInputManager.h"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include "BurgerEngine/Core/Engine.h"
#include "EventManager.h"
#include <SFML/Window.hpp>
//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::InitializeInput()
{

	//Set the glut input callback
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);

	//glutSpecialFunc(keyboardSpecialGL);
  
	glutMouseFunc(OnMouseClick);
	glutMotionFunc(OnMouseMotion);
	glutPassiveMotionFunc(OnMousePassiveMotion);
}

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::ProcessEvents()
{
	Engine& rEngine = Engine::GetInstance();

	sf::Event SFMLEvent;

	//go through all event since last frame
	// It's SFML specific taht we get the window
	while(rEngine.GetLibSpecificWindow().GetEvent(SFMLEvent))
	{
		switch(SFMLEvent.Type)
		{
		case sf::Event::KeyPressed:
			switch (SFMLEvent.Key.Code)
			{
			//case 27
			case sf::Key::Escape:
				rEngine.SetTerminate(true);
				break;
			default:
				Engine::GetInstance().GetEventManager().DispatchKeyboardDownKeyEvent(SFMLEvent.Key.Code);
				break;
			}
			break;
		}
	
	}
}

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::OnKeyboardUp(unsigned char a_cKey,int a_iX, int a_iY)
{
	Engine::GetInstance().GetEventManager().DispatchKeyboardUpKeyEvent(a_cKey);
}

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::OnKeyboardDown(unsigned char a_cKey,int a_iX, int a_iY)
{
	switch(a_cKey)
	{ 
	case 27:
		    //Shoudl send a quit event it not up to this class to tell "Engine you have to die!"
			Engine::GetInstance().SetTerminate(true);
			exit(0);
		break;
	default:
			Engine::GetInstance().GetEventManager().DispatchKeyboardDownKeyEvent(a_cKey);
		break;
	}

}


//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::OnMouseClick(int a_iButton, int a_iState, int a_iX, int a_iY)
{
	Engine::GetInstance().GetEventManager().DispatchMouseDownClick(a_iButton, a_iState, a_iX, a_iY);
}

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::OnMouseMotion(int a_iX, int a_iY)
{
	Engine::GetInstance().GetEventManager().DispatchMouseActiveMotion(a_iX, a_iY);
}

//--------------------------------------------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------------------------------------------
void SFMLInputManager::OnMousePassiveMotion(int a_iX, int a_iY)
{
	Engine::GetInstance().GetEventManager().DispatchMousePassiveMotion(a_iX, a_iY);

}