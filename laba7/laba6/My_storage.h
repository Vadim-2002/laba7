#pragma once

#using<system.dll>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

#include "Shapes.h"
#include <iostream>
#include <fstream>
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"

class My_storage
{
private:
    Shapes** objects;
    int size;

public:
    My_storage(int size)
    {
        this->size = size;
        objects = new Shapes * [size];
    }

    ~My_storage()
    {
        delete[] objects;
    }

    void setObject(int i, Shapes* object)
    {
        objects[i] = object;
    }

    int getCount()
    {
        return size;
    }

    Shapes& getObject(int i)
    {
        return *objects[i];
    }

    void nullObject(int i)
    {
        objects[i] = NULL;
    }

    void deleteObject(int index)
    {
        size--;

        Shapes** new_objects = new Shapes * [size];

        for (int i = 0; i < index; i++)
        {
            new_objects[i] = objects[i];
        }

        for (int i = index; i < size; i++)
        {
            new_objects[i] = objects[i + 1];
        }

        delete[] objects;

        objects = new_objects;
    }

    void addObjects(int index, Shapes* object)
    {
        size = index + 1;
        Shapes** new_objects = new Shapes * [size];

        for (int i = 0; i < index; i++)
            new_objects[i] = objects[i];

        delete[] objects;

        objects = new_objects;

        objects[index] = object;
    }

    int getVolume()
    {
        int volume = 0;

        for (int i = 0; i < size; i++)
            if (objects[i] != NULL)
                volume++;

        return volume;
    }

    void Save()
    {
        std::ofstream out;
        out.open("C:\\a.txt");

        if (out.is_open())
        {
            out << size << std::endl;
            for (int i = 0; i < size; i++)
            {
                objects[i]->Save();
            }
        }

        out.close();
    }

    void Load()
    {
        std::ifstream fin("C:\\a.txt");

        fin >> size;

        objects = new Shapes * [size];

        std::string name;

        for (int i = 0; i < size; i++)
        {
            fin >> name;
            if (name == "CCircle")
            {
                objects[i] = new CCircle(0, 0);
                objects[i]->Load(fin);
            }
            else
                if (name == "CSquare")
                {
                    objects[i] = new CSquare(0, 0);
                    objects[i]->Load(fin);
                }
                else
                    if (name == "CTriangle")
                    {
                        objects[i] = new CTriangle(0, 0);
                        objects[i]->Load(fin);
                    }
        }

        fin.close();
    }
};