//
// Created by suzum on 25-1-3.
//

#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "base_class.h"
using namespace std;
class Course : public Base {
    string date, name, subject, type;
    int number;
    static int course_count;

    public:
    Course(string d, string n, string s, int num, string t) {
        date=d;
        name=n;
        number=num;
        subject=s;
        type=t;
        course_count++;
    }

    ~Course () override {}


    void showinfo () override;
    void editinfo(string d, string n, string s, int num, string t);
    string getinfo() override;
    string static check_cnt();
    int static get_course_rank();
    string check_info(int n);
    string check_subjuct();
    string check_name();
    string check_date();

};
#endif //COURSE_H
