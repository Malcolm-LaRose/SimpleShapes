#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Settings.h"
#include "Wrapper.h"
#include "textureManager.h"

#include <SDL.h>

class GameObject {
public:

	GameObject(const char* texturePath, float x, float y);

	~GameObject();


	void update();

	void renderTexture();


private:

	float xPos;
	float yPos;

	SDL_Texture* O_texture;
	SDL_Rect srcRect;
	SDL_FRect destRect;

	const MySettings& settings = MySettings::getInstance();


};

#endif
