#include "textureManager.h"
#include "Wrapper.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>


	SDL_Texture* TextureManager::LoadTexture(const char* fileName) {

		SDL_Surface* tempSurface = IMG_Load(fileName);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(MySDLWrapper::renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		if (!tempSurface) {
			std::cout << "Texture not loaded!";
		}

		return tex;

	}