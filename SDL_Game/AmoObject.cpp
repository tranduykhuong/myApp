#include"AmoObject.h"

AmoObject::AmoObject() {
	rect_.x = 0;
	rect_.y = 0;
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = false;
	amo_type_ = NONE;
}

AmoObject::~AmoObject(){}

void AmoObject::HandleMove(const int &x_boder, const int &y_boder) {
	if (amo_type_ == 2) {
		rect_.x += x_val_;
		rect_.y += y_val_;
		if (rect_.x > x_boder || rect_.y > y_boder)
			is_move_ = false;
	}
	else if (amo_type_ == 1) {
		rect_.x += x_val_;
		if (rect_.x > x_boder || rect_.y > y_boder)
			is_move_ = false;
	}
}

void AmoObject::HandleInputAction(SDL_Event events) {

}