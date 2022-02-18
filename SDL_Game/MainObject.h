#pragma once
#include"BasicObject.h"
#include"Common_Function.h"
#include"AmoObject.h"
#include<vector>

#define WIDTH_MAIN_OBJECT 77
#define HEIGHT_MAIN_OBJECT 52

class MainObject : public BasicObject
{
public:
	MainObject();
	~MainObject() {};

	void HandleInputAction(SDL_Event events);
	void HandleMove();

	void setAmoList(vector<AmoObject*> amo_list) { p_amo_list = amo_list; }
	vector<AmoObject*>getAmoList() const { return p_amo_list; }
	void MakeAmo(SDL_Surface* g_screen);
private:
	int x_val_;
	int y_val_;

	vector<AmoObject*>p_amo_list;
};