#pragma once

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Wrapper.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};



#endif