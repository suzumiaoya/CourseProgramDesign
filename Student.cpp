//
// Created by suzum on 25-1-3.
//
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

void Student::showinfo() {
    cout<<"学号: "<<ID<<endl;
    cout<<"姓名: "<<name<<endl;
    cout<<"性别: "<<gender<<endl;
    cout<<"年龄: "<<age<<endl;
    cout<<"班级: "<<Class<<endl;
}

void Student::editinfo(int edit_id,string edit_name,char edit_gender,int edit_age,string edit_class) {
    edit_id==0? ID=ID:ID=edit_id;
    edit_name=="0"? name=name:name=edit_name;
    edit_gender=='0'? gender=gender:gender=edit_gender;
    edit_age==0? age=age:age=edit_age;
    edit_class=="0"? Class=Class:Class=edit_class;
}

string Student::getinfo() {
    string info;
    string str(1,gender);
    info.append("学号：");
    info.append(to_string(ID));
    info.append("\n姓名：");
    info.append(name);
    info.append("\n性别：");
    info.append(str);
    info.append("\n年龄：");
    info.append(to_string(age));
    info.append("\n班级：");
    info.append(Class);
    info.append("\n");

    return info;

}


string Student::checkname() {
    return name;
}

char Student::checkgender() {
    return gender;
}

int Student::checkage() {
    return age;
}

string Student::checkclass() {
    return Class;
}
