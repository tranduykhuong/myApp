#include"MainObject.h"

MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
}

void MainObject::HandleMove() {
	rect_.x += x_val_;
	if (rect_.x<0 || rect_.x + WIDTH_MAIN_OBJECT>SCREEN_WIDTH)
		rect_.x -= x_val_;

	rect_.y += y_val_;
	if (rect_.y<0 || rect_.y + HEIGHT_MAIN_OBJECT>SCREEN_HEIGHT - UNDER_LIMIT)
		rect_.y -= y_val_;
}

void MainObject::HandleInputAction(SDL_Event events) {
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ -= HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_DOWN:
			y_val_ += HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_LEFT:
			x_val_ -= HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_RIGHT:
			x_val_ += HEIGHT_MAIN_OBJECT / 10;
			break;
		}
	}
	else if (events.type == SDL_KEYUP) {
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ += HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_DOWN:
			y_val_ -= HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_LEFT:
			x_val_ += HEIGHT_MAIN_OBJECT / 10;
			break;
		case SDLK_RIGHT:
			x_val_ -= HEIGHT_MAIN_OBJECT / 10;
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN) {
		AmoObject* p_amo = new AmoObject;
		if (events.button.button == SDL_BUTTON_LEFT) {
			p_amo->LoadImg("laser.png");
			p_amo->setWidthHeight(WIDTH_LASER, HEIGHT_LASER);
			p_amo->set_amo_type(AmoObject::LASER);
		}
		else {
			p_amo->LoadImg("sphere.png");
			p_amo->setWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			p_amo->set_amo_type(AmoObject::SPHERE);
			p_amo->set_y_val(8);
		}

		p_amo->setRect(this->rect_.x + 75, this->rect_.y + this->rect_.h * 0.8);
		p_amo->set_is_move(true);
		p_amo_list.push_back(p_amo);
		p_amo->set_x_val(15);
	}
	else if (events.type == SDL_MOUSEBUTTONUP) {

	}
	else {

	}
}

void MainObject::MakeAmo(SDL_Surface* g_screen) {
	for (int i = 0; i < p_amo_list.size(); i++) {
		AmoObject* p_amo = p_amo_list[i];
		if (p_amo) {
			if (p_amo->get_is_move()) {
				p_amo->Show(g_screen);
				p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}
		else {
			if (!p_amo) {
				p_amo_list.erase(p_amo_list.begin() + i);

				delete p_amo;
				p_amo = NULL;
			}
		}
	}
}