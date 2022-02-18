#include"Common_Function.h"

SDL_Surface* SDL_commonFunc::LoadImage(string file_path) {
	SDL_Surface* load_img = NULL;
	SDL_Surface* optimize_img = NULL;

	load_img = IMG_Load(file_path.c_str());
	if (load_img) {
		optimize_img = SDL_DisplayFormat(load_img);
		SDL_FreeSurface(load_img);

		if (optimize_img != NULL) {
			UINT32 color_key = SDL_MapRGB(optimize_img->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimize_img, SDL_SRCCOLORKEY, color_key);
		}
	}
	return optimize_img;
}

void SDL_commonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

void SDL_commonFunc::CleanUp()
{
	SDL_FreeSurface(g_screen);
	SDL_FreeSurface(g_bkground);
}