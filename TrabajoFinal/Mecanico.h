#pragma once
#include "Entidad.h"

class Mecanico :public Entidad
{
public:
	Mecanico(int w, int h) :Entidad() {
		width = w;
		height = h;
		idy = 0;
		idx = 0;
	}

	~Mecanico() {}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 2.0, height * 2.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void Move(Graphics^ g) {
		idx++;

		if (idx > 7) {
			idx = 0;
		}
	}

	Rectangle get_Rectangle(){ return Rectangle(x, y, width * 2.0, height * 2.0); }

private:

};
