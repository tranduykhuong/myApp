#pragma once

#include<Windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#undef main
using namespace std;

const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;

namespace SDL_commonFunc
{
	SDL_Surface* LoadImage(string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
	void checkCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}
