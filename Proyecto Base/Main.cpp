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

SDL_Window* _gWindow = NULL;
SDL_Renderer* _gRenderer = NULL;
int main(int argc, char* args[]) {
	const Uint8* state;
	SDL_Init(SDL_INIT_VIDEO);
	bool success = true;
	//Create window
	_gWindow = SDL_CreateWindow("MEGAMAN THE GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create renderer for window
		_gRenderer = SDL_CreateRenderer(_gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (_gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(_gRenderer, 0xFF, 0xAA, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
		}
	}

	state = SDL_GetKeyboardState(NULL);
	SDL_Event event;

	do
	{
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests quit
			if (event.type == SDL_QUIT)
			{
				
			}
		}

		if (state[SDL_SCANCODE_ESCAPE])
		{
			
		}
		if (state[SDL_SCANCODE_1]) 
		{

		}
		if (state[SDL_SCANCODE_2]) 
		{

		}
	
		SDL_SetRenderDrawColor(_gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(_gRenderer);
		SDL_RenderPresent(_gRenderer);
	} while (true);
	
	system("pause");
	return 0;
}

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
{
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
		newTexture = SDL_CreateTextureFromSurface(_gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}


	return newTexture;
}