#pragma once

#include <iostream>
#include <fstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class Shapes
{
public:
	virtual void select() = 0;
	virtual void unselect() = 0;
	virtual bool reach(int x, int y) = 0;
	virtual bool is_select() = 0;

	virtual void draw_red(Graphics^ g) = 0;
	virtual void draw_blue(Graphics^ g) = 0;
	virtual void draw_green(Graphics^ g) = 0;

	virtual void change_the_size(int r) = 0;
	virtual void change_the_x(int x) = 0;
	virtual void change_the_y(int y) = 0;

	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getR() = 0;

	virtual void Save() = 0;
	virtual void Load(std::ifstream &fin) = 0;
};