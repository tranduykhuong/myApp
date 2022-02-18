#include "ThreatsObject.h"


ThreatsObject::ThreatsObject() {
	rect_.x = SCREEN_WIDTH;
	rect_.y = 0;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;

	x_val_ = 0;
	y_val_ = 0;
}

ThreatsObject::~ThreatsObject() {

}

void ThreatsObject::HandleMove(const int& x_border, const int& y_border) {
	rect_.x -= x_val_;
	if (rect_.x < 0) {
		rect_.x = SCREEN_WIDTH;
		int y_rand = rand() % 400;
		if (y_rand > SCREEN_HEIGHT - UNDER_LIMIT)
			y_rand *= 0.3;
		rect_.y = y_rand;
	}
}

void ThreatsObject::HandleInputAction(SDL_Event events) {

}