#pragma once
#include"Common_Function.h"
#include"BasicObject.h"

#define WIDTH_THREAT 80
#define HEIGHT_THREAT 33

class ThreatsObject : public BasicObject
{
public:
	ThreatsObject();
	~ThreatsObject();

	void HandleMove(const int& x_border, const int& y_border);
	void HandleInputAction(SDL_Event events);

	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val() { return x_val_; }
	int get_y_val() { return y_val_; }
private:
	int x_val_;
	int y_val_;
};

