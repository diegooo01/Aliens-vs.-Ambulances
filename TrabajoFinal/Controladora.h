#pragma once
#include "Ambulancia.h"
#include "Alien1.h"
#include "Alien2.h"
#include "Mecanico.h"
#include "Medicamento.h"
#include "Corazon.h"
#include "Hospital.h"
#include "File.h"
#include <vector>

using namespace std;
using namespace System;

class Controladora
{
public:
	Controladora(int cora) {
		contador_corazon = cora;
		cantidad_medi = 0;
		file = new File();
		file->ReadData();
	}
	~Controladora(){}

	void CrearAliens_uno(int w, int h, int n) {
		Random r;

		for (int i = 0; i < n; i++) {
			Alien1* a1 = new Alien1(w, h, r.Next(0, 2));

			aliens1.push_back(a1);
		}
	}

	void CrearAliens_dos(int w, int h, int n) {
		Random r;

		for (int i = 0; i < n; i++) {
			Alien2* a1 = new Alien2(w, h, r.Next(0, 2));

			aliens2.push_back(a1);
		}
	}

	void CrearMecanico(int w, int  h, int n2) {
		for (int i = 0; i < n2; i++) {
			Mecanico* m = new Mecanico(w, h);

			mecanicos.push_back(m);
		}
	}

	void CrearMedicamentos(int w, int h, int n) {
		for (int i = 0; i < n; i++) {
			Medicamento* m2 = new Medicamento(w, h);

			medicamentos.push_back(m2);
		}
	}

	void CrearCorazones(int w, int h, int px) {
		for (int i = 0; i < 1; i++) {

			px = px + 20;

			Corazon* c = new Corazon(w, h, px);

			corazones.push_back(c);
		}
	}

	void Draw_Everything(Graphics^ g, Bitmap^ bmpEnemy1, Bitmap^ bmpEnemy2, Bitmap^ bmpMecanico, Bitmap^ bmpMedicamento, Bitmap^ bmpCorazon) {
		for (int i = 0; i < aliens1.size(); i++) {
			aliens1[i]->Draw(g, bmpEnemy1);

		}

		for (int i = 0; i < aliens2.size(); i++) {
			aliens2[i]->Draw(g, bmpEnemy2);
		}

		for (int i = 0; i < mecanicos.size(); i++) {
			mecanicos[i]->Draw(g, bmpMecanico);

		}

		for (int i = 0; i < medicamentos.size(); i++) {
			medicamentos[i]->Draw(g, bmpMedicamento);

		}

		for (int i = 0; i < corazones.size(); i++) {
			corazones[i]->Draw(g, bmpCorazon);

		}
	}

	void Move_Everything(Graphics^ g) {
		for (int i = 0; i < aliens1.size(); i++) {
			aliens1[i]->Move(g);

		}

		for (int i = 0; i < aliens2.size(); i++) {
			aliens2[i]->Move(g);

		}

		for (int i = 0; i < mecanicos.size(); i++) {
			mecanicos[i]->Move(g);

		}

		for (int i = 0; i < medicamentos.size(); i++) {
			medicamentos[i]->Move(g);

		}

	}

	void Collision(Graphics^ g, Ambulancia* ambulancia, Hospital* hospital) {
		for (int i = 0; i < mecanicos.size(); i++) {

			if (mecanicos[i]->get_Rectangle().IntersectsWith(ambulancia->get_Rectangle())) {

				mecanicos[i]->set_visibility(false);
				++contador_corazon;

			}

		}

		for (int i = 0; i < medicamentos.size(); i++) {

			if (medicamentos[i]->get_Rectangle().IntersectsWith(ambulancia->get_Rectangle())) {

				medicamentos[i]->set_visibility(false);
				++cantidad_medi;
			}

		}

		for (int i = 0; i < aliens1.size(); i++) {

			if (aliens1[i]->get_Rectangle().IntersectsWith(ambulancia->get_Rectangle())) {

				_sleep(80);
				aliens1[i] = new Alien1(530 / 5, 201 / 2, 0);
				ambulancia->Set_valores();
				--contador_corazon;
			}

		}

		for (int i = 0; i < aliens2.size(); i++) {

			if (aliens2[i]->get_Rectangle().IntersectsWith(ambulancia->get_Rectangle())) {

				_sleep(80);
				if (i % 2 == 0) {
					aliens2[i] = new Alien2(348 / 6, 272 / 4, 0);
				}
				else {
					aliens2[i] = new Alien2(348 / 6, 272 / 4, 1);
				}
				ambulancia->Set_valores();
				--contador_corazon;

			}

		}

		//Borracion

		for (int i = 0; i < mecanicos.size(); i++) {
			if (mecanicos[i]->get_visibility() == false) {
				mecanicos.erase(mecanicos.begin() + i); //Borra un objeto del arreglo
			}
		}

		for (int i = 0; i < medicamentos.size(); i++) {
			if (medicamentos[i]->get_visibility() == false) {
				medicamentos.erase(medicamentos.begin() + i); //Borra un objeto del arreglo
			}
		}

	}

	int get_corazones() { return contador_corazon; }
	int get_medicinas(){ return cantidad_medi; }
	int get_size(){ return medicamentos.size(); }

private:
	vector<Alien1*> aliens1;
	vector<Alien2*> aliens2;
	vector<Mecanico*> mecanicos;
	vector<Medicamento*>medicamentos;
	vector<Corazon*>corazones;

	int contador_corazon;
	int cantidad_medi;

	File* file;

};