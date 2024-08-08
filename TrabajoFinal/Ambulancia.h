#pragma once
#include "Entidad.h"

class Ambulancia: public Entidad
{
public:

	Ambulancia(int w, int h, int px, int py, int pdx, int pdy):Entidad() {
		width = w;
		height = h;
		dx = pdx;
		dy = pdy;
		x = px;
		y = py;
		idx = idy = 0;
	}
	~Ambulancia() {}

	void Draw(Graphics^ g, Bitmap^ bmp){
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.5, height * 1.5);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void Move(Graphics^ g, char i) {
		switch (i) {

		case 'A':
			if (x > 0) {
				idy = 1;
				idx = 0;
				x -= dx;
			}
			break;

		case 'D':
			if (x + width * 1.5 < g->VisibleClipBounds.Width) {
				idy = 0;
				idx = 0;
				x += dx;
			}
			break;

		case 'W':
			if (y > 0) {
				idy = 1;
				idx = 4;
				y -= dy;
			}
			break;

		case 'S':
			if (y + height * 1.5 < g->VisibleClipBounds.Height) {
				idy = 0;
				idx = 4;
				y += dy;
			}
			break;
		}
	}

	void Set_valores() {
		x = 20;
		y = 50;
		dx = 20;
		dy = 20;
	}

	Rectangle get_Rectangle(){ return Rectangle(x, y, width * 1.5, height * 1.5); }


private:

};
