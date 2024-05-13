#include "Wrapper.h"
#include "Settings.h"
#include "textureManager.h"
#include "GameObject.h"

#include <iostream>


	MySDLWrapper::MySDLWrapper() : settings(MySettings::getInstance()), screenWidth(settings.initScreenWidth), screenHeight(settings.initScreenHeight) {
		init(); // Automatically runs init when instantiating MySDLWrapper

	}


	void MySDLWrapper::init() {
		running = true;

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			running = false;
		}
		else
		{

			// Create window
			window = SDL_CreateWindow("SDL Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				running = false;
			}
			else
			{
				// Create renderer for window
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				if (renderer == NULL)
				{
					printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
					running = false;
				}

				// Initialize SDL_ttf
				else if (TTF_Init() != 0) {
					printf("SDL_ttf initialization failed");
					running = false;
				}

				// Init background
				SDL_SetRenderDrawColor(renderer, settings.bgColor.r, settings.bgColor.g, settings.bgColor.b, settings.bgColor.a);



			}
		}

		if (!running)
		{
			SDL_Quit();
			renderer = nullptr;
			window = nullptr;
		}

		testPlayer = new GameObject("Untitled.png", 0, 0);

	}

	void MySDLWrapper::handleEvents() {
		SDL_Event event;
		SDL_PollEvent(&event); // Pointer to event

		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;

			// Add cases

		default:
			break;

		}

	}

	void MySDLWrapper::update(Uint32 frameTime) {
		// Perform other updates here as needed


		testPlayer->update();

		count++;
	}


	void MySDLWrapper::render(Uint32 frameTime) {
		SDL_RenderClear(renderer);
		renderBG();

		// Add stuff to render
		testPlayer->renderTexture();
		SDL_RenderPresent(renderer);

		// capFPS(settings.frameRateCap, MyTimer_us::getFrameDuration());
	}

	void MySDLWrapper::clean() {

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		std::cout << "Cleanup complete!";

	}

	bool MySDLWrapper::isRunning() {
		return running;
	}

	uint64_t MySDLWrapper::getCount() {
		return count;
	}

	void MySDLWrapper::renderBG() {
		SDL_SetRenderDrawColor(renderer, settings.bgColor.r, settings.bgColor.g, settings.bgColor.b, settings.bgColor.a);
		SDL_RenderClear(renderer);
	}
