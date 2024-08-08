#pragma once
#include "Entidad.h"

class Alien1 :public Entidad
{
public:
	Alien1(int w, int h, int d) :Entidad() {
		width = w;
		height = h;
		direction = d;
		dx = dy = 20;
		idy = 1;
		idx = 0;
	}
	~Alien1() {

	}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	void Move(Graphics^ g) {
		if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 90 || x >= 550 && y >= 400) dx *= -1;

		if (dx > 0) {
			idy = 1;
		}
		else idy = 0;
		x += dx;

		idx++;
		if (idx > 4)idx = 0;
	}

	Rectangle get_Rectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

private:

};

