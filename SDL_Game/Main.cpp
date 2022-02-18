#include"Common_Function.h"
#include"MainObject.h"
#include"ThreatsObject.h"

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (g_screen == NULL)
		return false;
	
	return true;
}

int main(int arc, char* argv[]) 
{
	bool is_run_bk = true;
	int bkgn_x = 0;
	bool is_quit = false;

	if (!Init())
		return 0;

	g_bkground = SDL_commonFunc::LoadImage("bg4800.png");
	if (!g_bkground)
		return 0;
	
	// Make MainObject
	MainObject human_object;
	human_object.setRect(300, 200);
	bool ret = human_object.LoadImg("plane_fly.png");
	if (!ret)
		return 0;

	//Make ThreatsObject
	ThreatsObject* p_threat = new ThreatsObject();
	if (!p_threat->LoadImg("af1.png")) {
		return 0;
	}
	int y_rand = rand() % 400;
	if (y_rand > SCREEN_HEIGHT - 270)
		y_rand *= 0.3;
	p_threat->setRect(SCREEN_WIDTH, y_rand);
	p_threat->set_x_val(5);

	while (!is_quit) {
		while (SDL_PollEvent(&g_even)) {
			if (g_even.type == SDL_QUIT) {
				is_quit = true;
				break;
			}

			human_object.HandleInputAction(g_even);
		}

		// Apply background
		/*bkgn_x -= 2;
		SDL_commonFunc::ApplySurface(g_bkground, g_screen, bkgn_x, 0);
		SDL_commonFunc::ApplySurface(g_bkground, g_screen, bkgn_x + SCREEN_WIDTH, 0);
		if (bkgn_x <= -SCREEN_WIDTH)
			bkgn_x = 0;*/

		if (is_run_bk) {
			bkgn_x -= 2;
			if (bkgn_x <= -(WIDTH_BACKGROUND - SCREEN_WIDTH) + 500)
				bkgn_x += 1;
			if (bkgn_x <= -(WIDTH_BACKGROUND - SCREEN_WIDTH))
				is_run_bk = false;
		}
		SDL_commonFunc::ApplySurface(g_bkground, g_screen, bkgn_x, 0);

		// Implement main object
		human_object.HandleMove();
		human_object.Show(g_screen);
		//Bắn đạn
		human_object.MakeAmo(g_screen);

		// Implement Threats object
		p_threat->Show(g_screen);
		p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);

		// Update screen
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	SDL_commonFunc::CleanUp();
	SDL_Quit();

	return 0;
}