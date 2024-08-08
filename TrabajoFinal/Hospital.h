#pragma once
#include "Entidad.h"

class Hospital :public Entidad
{
public:
	Hospital(int w, int h) :Entidad() {
		x = 600;
		y = 400;
		width = w;
		height = h;
		idy = 0;
		idx = 0;
	}

	~Hospital(){}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	Rectangle get_Rectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

private:

};
