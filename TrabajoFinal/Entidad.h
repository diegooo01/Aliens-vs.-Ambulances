#pragma once
#include <iostream>

using namespace System::Drawing;
using namespace System;

class Entidad 
{
public:
	Entidad() {
		visibility = true;
		x = 70 + rand() % (601 - 60);
		y = 70 + rand() % (401 - 60);
	}

	~Entidad() {}

	//METODOS:

	virtual void Draw(Graphics^ g, Bitmap^ bmp) {}
	virtual void Move(Graphics^ g){}

	void set_visibility(bool v) {
		visibility = v;
	}
	bool get_visibility() {
		return visibility;
	}

	//GET:
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}

protected:
	int x, y;
	int dx, dy;
	int idx, idy;
	int width, height;
	int direction;
	bool visibility;
};
