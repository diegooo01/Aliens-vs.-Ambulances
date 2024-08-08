#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class File
{
public:
	File() {}
	~File(){}

	//Metodos:

	void ReadData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {

			fileRead.close();

			fileWrite.open("configuration.txt", ios::out);
			fileWrite << "20" << endl; //x
			fileWrite << "50" << endl;//y
			fileWrite << "20" << endl;//dx
			fileWrite << "20" << endl;//dy
			fileWrite.close();

			fileRead.open("configuration.txt", ios::in);

		}

		getline(fileRead, text);

		x = atoi(text.c_str());

		getline(fileRead, text);
		y = atoi(text.c_str());

		getline(fileRead, text);
		dx = atoi(text.c_str());

		getline(fileRead, text);
		dy = atoi(text.c_str());

		fileRead.close();
	}

	int get_x(){ return x; }
	int get_y(){ return y; }
	int get_dx(){ return dx; }
	int get_dy(){ return dy; }

private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int x, y, dx, dy;
};
