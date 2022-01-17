#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Shapes.h"
#include <iostream>
#include <fstream>

class CCircle : public Shapes
{
protected:
    int x, y;
    int r = 80;
    bool marked = false;
    std::string name = "CCircle";

public:
    CCircle(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void draw_red(Graphics^ g) override
    {
        if (marked == false)
            g->DrawEllipse(Pens::Red, x - r / 2, y - r / 2, r, r);
        else
            g->DrawEllipse(Pens::Black, x - r / 2, y - r / 2, r, r);
    }

    void draw_green(Graphics^ g) override
    {
        if (marked == false)
            g->DrawEllipse(Pens::Green, x - r / 2, y - r / 2, r, r);
        else
            g->DrawEllipse(Pens::Black, x - r / 2, y - r / 2, r, r);
    }

    void draw_blue(Graphics^ g) override
    {
        if (marked == false)
            g->DrawEllipse(Pens::Blue, x - r / 2, y - r / 2, r, r);
        else
            g->DrawEllipse(Pens::Black, x - r / 2, y - r / 2, r, r);
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
        if (((x - this->x) * (x - this->x)) + ((y - this->y) * (y - this->y)) <= (r * r))
            return true;
        else
            return false;
    }

    bool is_select() override
    {
        return marked;
    }

    void change_the_size(int r) override
    {
        this->r = r;
    }

    void change_the_x(int x) override
    {
        this->x += x;
    }

    void change_the_y(int y) override
    {
        this->y += y;
    }

    int getX() override
    {
        return x;
    }

    int getY() override
    {
        return y;
    }

    int getR() override
    {
        return r;
    }

    void Save() override
    {
        std::ofstream out("C:\\a.txt", std::ios::app);

        if (out.is_open())
        {
            out << name << std::endl;
            out << x << std::endl;
            out << y << std::endl;
            out << r << std::endl;

        }

        out.close();
    }

    void Load(std::ifstream &fin) override
    {
        fin >> x;
        fin >> y;
        fin >> r;
    }
};