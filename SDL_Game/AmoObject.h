#pragma once
#include"BasicObject.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

class AmoObject : public BasicObject {
private:
	int x_val_;
	int y_val_;
	bool is_move_;
	int amo_type_;

public:
	enum AmoType {
		NONE = 0,
		LASER = 1,
		SPHERE = 2
	};

	AmoObject();
	~AmoObject();
	void HandleInputAction(SDL_Event events);
	void HandleMove(const int& x_boder, const int& y_boder);

	bool get_is_move() const { return is_move_; }
	void set_is_move(bool move) { is_move_ = move; }

	int get_amo_type() const { return amo_type_; }
	void set_amo_type(int type) { amo_type_ = type; }

	void setWidthHeight(const int& w, const int& h) { rect_.w = w; rect_.h = h; }

	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }
};