#pragma once
#include "Entidad.h"

class Corazon :public Entidad
{
public:
	Corazon(int w, int h, int px) :Entidad() {
		x = px;
		y = 15;
		width = w;
		height = h;
		idy = 0;
		idx = 0;
	}
	~Corazon() {}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.05, height * 0.05);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

};

