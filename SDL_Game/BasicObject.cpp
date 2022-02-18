#include"BasicObject.h"

BasicObject::BasicObject() {
	rect_.x = 0;
	rect_.y = 0;
	p_object_ = NULL;
}

BasicObject::~BasicObject() {
	if (p_object_)
		SDL_FreeSurface(p_object_);
}

bool BasicObject::LoadImg(const char* filename) {
	p_object_ = SDL_commonFunc::LoadImage(filename);
	if (p_object_)
		return true;
	return false;
}

void BasicObject::Show(SDL_Surface* des) {
	if (p_object_)
		SDL_commonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
}
