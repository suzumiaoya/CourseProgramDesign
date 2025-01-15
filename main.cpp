#include <iostream>
#include "Student.h"
#include "Course.h"
#include "function.h"
#include <map>
#include <filesystem>
#include <fstream>
#include <iomanip>
using namespace std;
namespace fs=filesystem;

void create_dictionary() {
    fs::create_directory("C://Users//suzum//CLionProjects//CourseDesign//cache");
    fs::create_directory("C://Users//suzum//CLionProjects//CourseDesign//cache//students");
    fs::create_directory("C://Users//suzum//CLionProjects//CourseDesign//cache//courses");
    fs::create_directory("C://Users//suzum//CLionProjects//CourseDesign//save");
}

int main() {
    create_dictionary();
    int width=40,padding;
    while(1) {
        system("cls");

    }

    return 0;
}
