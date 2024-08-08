#pragma once
#include "Entidad.h"

class Alien2 :public Entidad
{
public:

	Alien2(int w, int h, int d) :Entidad() {
		width = w;
		height = h;
		direction = d;
		dx = dy = 20;
		idy = 2;
		idx = 0;
	}

	~Alien2(){}

	void Draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.3, height * 1.3);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}
	void Move(Graphics^ g) {

		if (direction == 1) {
			if (x + width * 1.3 > g->VisibleClipBounds.Width || x < 90 || x >= 550 && y >= 400) dx *= -1;

			if (dx > 0) {
				idy = 2;
			}
			else idy = 1;
			x += dx;
		}
		else {
			if (y + height * 1.3 > g->VisibleClipBounds.Height || y < 0 || y >= 400 && x >= 550) dy *= -1;

			if (dy > 0) {
				idy = 0;
			}
			else idy = 3;

			y += dy;
		}

		idx++;
		if (idx > 5)idx = 0;

	}

	Rectangle get_Rectangle() {
		return Rectangle(x, y, width * 1.3, height * 1.3);
	}

private:

};
