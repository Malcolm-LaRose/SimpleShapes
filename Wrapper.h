#pragma once


#ifndef WRAPPER_H
#define WRAPPER_H

#include "Settings.h"
#include "GameObject.h"
#include "textureManager.h"

#include <SDL.h>
#include <SDL_ttf.h>

class MySDLWrapper { // Should be turned into GameX or SimX when implemented
public:

	MySDLWrapper();


	void init();

	void handleEvents();

	void update(Uint32 frameTime);

	void render(Uint32 frameTime);

	void clean();

	bool isRunning();

	uint64_t getCount();

	static SDL_Renderer* renderer;

private:
	const MySettings& settings;

	bool running;
	SDL_Window* window;

	SDL_Texture* testText;
	GameObject* testPlayer;

	int screenWidth; // Can change with user input
	int screenHeight;

	uint64_t count;


	// Internal member functions

	void renderBG();

};


#endif