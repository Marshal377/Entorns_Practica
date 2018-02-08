#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
#include <vector>

#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 800
#define FPS 60

unsigned int lastTime = 0, currentTime, deltaTime;
float msFrame = 1 / (FPS / 1000.0f);

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);

int main(int argc, char* args[]) {

	

	return 0;
}

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}