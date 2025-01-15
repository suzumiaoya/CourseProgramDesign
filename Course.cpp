//
// Created by suzum on 25-1-3.
//
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

int Course::course_count=0;

void Course::showinfo() {
    cout<<"缺课日期："<<date<<endl;
    cout<<"节数序号："<<number<<endl;
    cout<<"课程名称："<<subject<<endl;
    cout<<"学生姓名："<<name<<endl;
    cout<<"缺课类型"<<type<<endl;
}

void Course::editinfo(string d, string n, string s, int num, string t) {
    d=="0"? date=date:date=d;
    n=="0"? name=name:name=n;
    num==0? number=number:number=num;
    s=="0"? subject=subject:subject=s;
    t=="0"? type=type:type=t;
}

string Course::getinfo() {
    string info;

    info.append("缺课日期：");
    info.append(date);
    info.append("\n节数序号：");
    info.append(to_string(number));
    info.append("\n课程名称：");
    info.append(subject);
    info.append("\n学生姓名：");
    info.append(name);
    info.append("\n缺课类型：");
    info.append(type);

    return info;
}

string Course::check_cnt() {
    return to_string(course_count);
}

string Course::check_info(int n) {
    switch(n) {
        case 1: return name;
        case 2: return subject;
        case 3: return date;
        case 4: return to_string(number);
        case 5: return type;

    }
}

int Course::get_course_rank() {
    return course_count;
}

string Course::check_name() {
    return name;
}

string Course::check_subjuct() {
    return subject;
}

string Course::check_date() {
    return date;
}









