//
// Created by suzum on 25-1-3.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "base_class.h"
using namespace std;
class Student : public Base{
    int ID;
    string name;
    char gender;
    int age;
    string Class;
    public:
    Student(int id, string n, char g, int a, string c)
    {
        ID=id;name=n;gender=g;age=a;Class=c;
    }

    ~Student() override {}


    void showinfo() override;
    void editinfo(int edit_id,string edit_name,char edit_gender,int edit_age,string edit_class);
    string checkname();
    char checkgender();
    int checkage();
    string checkclass();
    string getinfo() override;
};

#endif //STUDENT_H
