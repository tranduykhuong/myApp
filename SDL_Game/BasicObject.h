#pragma once
#include"Common_Function.h"

const int UNDER_LIMIT = 270;

class BasicObject {
public:
	BasicObject();
	~BasicObject();
	void Show(SDL_Surface* des);
	bool LoadImg(const char* filename);

	void setRect(const int& x,const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect getRect() const { return rect_; }
	SDL_Surface* getObject() const { return p_object_; }
protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};