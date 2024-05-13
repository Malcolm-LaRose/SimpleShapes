#include "Wrapper.h"
#include "Settings.h"
#include "textureManager.h"
#include "GameObject.h"


// Constructor definition
GameObject::GameObject(const char* texturePath, float x, float y) {
    // Load texture using the TextureManager
    O_texture = TextureManager::LoadTexture(texturePath);

    // Set initial position
    xPos = x;
    yPos = y;
}

// Destructor definition
GameObject::~GameObject() {
    // Clean up resources, if necessary
}

// Update method definition
void GameObject::update() {
    // Update position or other properties
    xPos++;
    yPos++;

    // Update source and destination rectangles, if necessary
    srcRect.h = 200;
    srcRect.w = 200;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

// Render method definition
void GameObject::renderTexture() {
    // Render the texture using the renderer from MySDLWrapper
    SDL_RenderCopyF(MySDLWrapper::renderer, O_texture, &srcRect, &destRect);
}
