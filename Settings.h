#pragma once


#ifndef SETTINGS_H
#define SETTINGS_H

#include "color.h"

#include <SDL.h>
#include <string>

struct MySettings {

	static MySettings& getInstance() {
		static MySettings instance;
		return instance; // Returns a static reference to the MySettings struct
	}

	const float initScreenWidth = 1920.0;
	const float initScreenHeight = 1080.0;

	const SDL_FPoint screenCenter = { initScreenWidth / 2 , initScreenHeight / 2 };

	const std::string windowTitle = "MyWindow";

	const SDL_Color bgColor = Color::getSDLColor(Color::EIGENGRAU);

	const int frameRateCap = 244; // Set to 1000 for ~max (unstable)




};

#endif