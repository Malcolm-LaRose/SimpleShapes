#include "color.h"
#include "Timer.h" // USING SDL UNTIL THIS IS WORKING PROPERLY
#include "Settings.h"
#include "Wrapper.h"
#include "textureManager.h"
#include "GameObject.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <chrono>
#include <sstream> 
#include <string> // Inherited from sstream
#include <iostream>
#include <thread>
#include <stdio.h> // Inherited from SDL.h

#include <windows.h>


// Conventions
// O_classMember --> Unique name for an object class member


// Known problems
// FPS is coupled to game time, can't change FPS without changing the speed of the game]

// Forward declarations

// Globals
SDL_Renderer* MySDLWrapper::renderer = nullptr;




int main(int argc, char* argv[]) {

	// Object Instantiation

	Uint32 frameStart = 0;
	int frameTime = 0;

	const MySettings& settings = MySettings::getInstance();

	MySDLWrapper* wrapper = nullptr; // Wrapper points toward the MySDLWrapper class

	wrapper = new MySDLWrapper;

	MyTimer_us* timer = nullptr;

	timer = new MyTimer_us;


	// Main loop
	while (wrapper->isRunning()) {
		// timer->markFrameBeginTime();

		frameStart = SDL_GetTicks();

		wrapper->handleEvents(); // Event handling
		wrapper->update(frameTime); // Game logic
		wrapper->render(frameTime); // Rendering

		// timer->markFrameEndTime(); 
		// timer->logFPS();
		// system("cls");
		// std::cout << "\rAVG SDL FPS: " << (wrapper->getCount() * 1000) / SDL_GetTicks() << std::endl; --> Agrees with below
		std::cout << "\rAVG FPS: " << (wrapper->getCount() * 1000000) / timer->getTotalTimeElapsed().count() << std::flush;

		frameTime = SDL_GetTicks() - frameStart;

		if ((1000 / settings.frameRateCap) > frameTime) {
			SDL_Delay((1000 / settings.frameRateCap) - frameTime);
		}


	}

	// Quit
	wrapper->clean();
	timer = nullptr;
	wrapper = nullptr;

	return 0;

}