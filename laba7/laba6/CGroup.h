#include "Shapes.h"
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class CGroup: public Shapes
{
private:
	int size = 0;
	int count = 0;
	Shapes** group;
	bool marked = true;
	std::string name = "CGroup";

	int maxX()
	{
		int max_x = -1;

		for (int i = 0; i < size; i++)
		{
			if (group[i]->getX() > max_x)
				max_x = group[i]->getX();
		}

		return max_x;
	}

	int minX()
	{
		int min_x = 100000;

		for (int i = 0; i < size; i++)
		{
			if (group[i]->getX() < min_x)
				min_x = group[i]->getX();
		}

		return min_x;
	}

	int maxY()
	{
		int max_y = -1;

		for (int i = 0; i < size; i++)
		{
			if (group[i]->getY() > max_y)
				max_y = group[i]->getY();
		}

		return max_y;
	}

	int minY()
	{
		int min_y = 100000;

		for (int i = 0; i < size; i++)
		{
			if (group[i]->getY() < min_y)
				min_y = group[i]->getY();
		}

		return min_y;
	}

	int maxR()
	{
		int max_r = -1;

		for (int i = 0; i < size; i++)
		{
			if (group[i]->getR() > max_r)
				max_r = group[i]->getR();
		}

		return max_r;
	}

public:
	CGroup(int size)
	{
		this->size = size;
		group = new Shapes * [size];
	}

	~CGroup()
	{
		delete[] group;
	}

	void add_to_group(int i, Shapes* object)
	{
		group[i] = object;
	}

	int getCount()
	{
		return size;
	}

	void expand_the_group(Shapes* object)
	{
		int size_new = size + 1;
		Shapes** new_objects = new Shapes * [size_new];

		for (int i = 0; i < size; i++)
			new_objects[i] = group[i];

		delete[] group;

		group = new_objects;

		group[size] = object;

		size = size_new;
	}

	void select() override
	{
		marked = true;
	}

	void unselect() override
	{
		marked = false;
	}

	bool reach(int x, int y) override
	{
		return 0;
	}

	bool is_select() override
	{
		return marked;
	}

	void draw_red(Graphics^ g) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->draw_red(g);
		}
	}

	void draw_blue(Graphics^ g) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->draw_blue(g);
		}
	}

	void draw_green(Graphics^ g) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->draw_green(g);
		}
	}

	void change_the_size(int r) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->change_the_size(r);
		}
	}

	void change_the_x(int x) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->change_the_x(x/2);
		}
	}

	void change_the_y(int y) override
	{
		for (int i = 0; i < size; i++)
		{
			group[i]->change_the_y(y/2);
		}
	}

	int getX() override
	{
		return (minX() + maxX()) / 2;
	}

	int getY() override
	{
		return (minY() + maxY()) / 2;
	}

	int getR() override
	{
		return maxR();
	}

	void Save()
	{
		std::ofstream out;
		out.open("C:\\a.txt");

		if (out.is_open())
		{
			out << name << std::endl;
			out << size << std::endl;

		}

		out.close();
	}

	void Load(std::ifstream &fin) override
	{
		fin >> size;
	}
};