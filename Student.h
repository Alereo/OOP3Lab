#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <QString>
#include <fstream>
#include "funcs.h"
#include "Boost.h"

using namespace std;

class Student_Mullayarov
{
    friend class boost::serialization::access;
protected:

public:
    string name,surname;
    double mark;
    int age;
    Student_Mullayarov();
    virtual void showStudent(ostream& out);
    virtual void createStudent(istream& in);
    virtual ~Student_Mullayarov();
    virtual int* countLen();
    virtual void draw(QPainter& painter,int x, int* y);
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& name;
        ar& surname;
        ar& age;
        ar& mark;
    }
};



