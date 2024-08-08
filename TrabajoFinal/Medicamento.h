#pragma once
#include "Entidad.h"

class Medicamento :public Entidad
{
public:
	Medicamento(int w, int h) :Entidad() {
		width = w;
		height = h;
		idy = 0;
		idx = 0;
	}

	~Medicamento(){}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void Move(Graphics^ g) {
		idx++;

		if (idx > 8) {
			idx = 0;
		}
	}

	Rectangle get_Rectangle(){ return Rectangle(x, y, width * 1.0, height * 1.0); }

private:

};