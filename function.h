//
// Created by suzum on 25-1-3.
//
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <map>
#include <ctime>
#include <sstream>
#include <vector>
#include "Student.h"
#include "Course.h"
#include <regex>

using namespace std;

map <int,Student*> inline students;
map <int,Course*> inline courses;

void inline cache_create(string const& path,string const& input);
void inline save_create(string const& path,string const& input);
void inline create_select(string const& path1, string const& path2, string const& input);
void inline create_trigger(string const& path1,  string const& input);
void inline create_trigger_2(string const& path1,  string const& input);
void inline delete_stu_inf(int ID2Delete);
void inline delete_course_inf(int ID2Delete);
int checkkey(string key);
string get_time();
string inline c_to_string(char s) {
    string str(1,s);
    return str;
}

//
//学生与课程信息的添加函数
//
void inline add_stu_inf() {
    cout<<"请输入要添加的学生信息，一次输入一行。"<<endl;
    cout<<"请输入学生姓名：";
    string name;
    cin>>name;
    cout<<"请输入学生学号：";
    int id;
    cin>>id;
    while(students.contains(id)) {
        cout << "学生学号不得相同！所添加学号与现有学号重复！" << endl;
        cout << "是否重新输入学号?(Y/N):";
        char input;
        cin>>input;
        if(input == 'N') {
            return ;
        }
        else {
            cout<<"请重新输入学生学号:";
            cin>>id;
        }
    }

    cout<<"请输入学生性别(M/F)：";
    char gender;
    cin>>gender;
    while(gender!='M'&&gender!='F') {
        cout<<"未支持的性别格式！请重新输入：";
        cin>>gender;
    }
    cout<<"请输入学生年龄：";
    int age;
    cin>>age;
    cout<<"请输入学生班级：";
    string inclass;
    cin>>inclass;

    Student* ptr_stu = new Student(id,name,gender,age,inclass);
    students[id]=ptr_stu;
}

void inline add_course_inf() {
    cout<<"请输入要添加的缺课记录，一次输入一行。"<<endl;
    cout<<"请输入学生姓名：";
    string name;
    cin>>name;
    cout<<"请输入缺课日期 (格式：年/月/日) ：";
    string date;
    cin>>date;
    cout<<"请输入缺课的序号：";
    int number;
    cin>>number;
    cout<<"请输入缺课的课程名称：";
    string subject;
    cin>>subject;
    cout<<"请输入缺课类型 (迟到/早退/请假/旷课) ：";
    string type;
    cin>>type;
    while((type!="迟到"&&type!="早退")&&(type!="请假"&&type!="旷课")) {
        cout<<"未支持的缺课类型！请重新输入:";
        cin>>type;
    }

    Course* ptr=new Course(date, name, subject, number, type);
    courses[Course::get_course_rank()]=ptr;
}
//
//学生与课程信息的显示函数
//
void inline show_stu_inf_simply() {

    cout<<"现有的学生记录如下:"<<endl;
    for(auto it=students.begin();it!=students.end();it++) {
        cout<<"学号:"<<it->first<<"|"<<"姓名:"<<it->second->checkname()<<endl;
    }

}

void inline show_stu_inf_in_detail() {

    cout<<"现有的学生记录如下:"<<endl<<"----------------------------------------";
    for(auto it=students.begin();it!=students.end();it++) {
        it->second->showinfo();
        cout<<"----------------------------------------"<<endl;
    }

}

void inline show_course_inf() {
    cout<<"现有的缺课记录如下:"<<endl<<"----------------------------------------";
    for(auto it=courses.begin();it!=courses.end();it++) {
        cout<<"课程编号:"<<it->first<<endl;
        it->second->showinfo();
        cout<<"----------------------------------------"<<endl;
    }
}
//
//学生与课程信息的删除函数
//
void inline delete_stu_info_trigger() {
    show_stu_inf_simply();
    cout<<"请选择单项/多项删除:"<<endl;
    cout<<"[1]单项删除"<<endl<<"[2]多项删除:";
    char input;
    cin>>input;
    if(input == '1') {
        cout<<"请输入要删除的学生的学号:";
        int ID2Delete;
        cin>>ID2Delete;
        delete_stu_inf(ID2Delete);
    }
    else if(input == '2') {
        cout<<"请输入要删除的学生的学号，每个学号间以空格分隔:";
        string input_id;
        cin>>input_id;
        vector<int> ID2Delete;
        stringstream ss(input_id);
        while(ss>>input_id) {
            ID2Delete.push_back(stoi(input_id));
        }
        int id2delete;
        for(auto it=ID2Delete.begin();it!=ID2Delete.end();it++) {
            id2delete=*it;
            delete_stu_inf(id2delete);
        }
    }
    else {
        cout<<"不受支持的类型!"<<endl;
    }
}

void inline delete_stu_inf(int ID2Delete) {

    auto it = students.find(ID2Delete);
    if (it != students.end()) {
        delete it->second;
        students.erase(it);
        cout<<"已成功消除学号为\""<<ID2Delete<<"\"的学生记录!"<<endl;
    } else {
        cout << "未查询到对应学号的学生信息！" << endl;
    }

}

void inline delete_course_info_trigger() {
    show_course_inf();
    cout<<"请选择单项/多项删除:"<<endl;
    cout<<"[1]单项删除"<<endl<<"[2]多项删除:";
    char input;
    cin>>input;
    if(input == '1') {
        cout<<"请输入要删除的缺课记录的编号:";
        int ID2Delete;
        cin>>ID2Delete;
        delete_course_inf(ID2Delete);
    }
    else if(input == '2') {
        cout<<"请输入要删除的缺课记录的编号，每个编号间以空格分隔:";
        string input_id;
        cin>>input_id;
        vector<int> ID2Delete;
        stringstream ss(input_id);
        while(ss>>input_id) {
            ID2Delete.push_back(stoi(input_id));
        }
        int id2delete;
        for(auto it=ID2Delete.begin();it!=ID2Delete.end();it++) {
            id2delete=*it;
            delete_course_inf(id2delete);
        }
    }
    else {
        cout<<"不受支持的类型!"<<endl;
    }
}

void inline delete_course_inf(int ID2Delete) {

    auto it = courses.find(ID2Delete);
    if (it != courses.end()) {
        delete it->second;
        courses.erase(it);
        cout<<"已成功消除编号为\""<<ID2Delete<<"\"的缺课记录!"<<endl;
    } else {
        cout << "未查询到对应编号的缺课信息！" << endl;
    }

}

//
//学生和课程记录的编辑菜单，作为查找函数的内嵌
//
void inline edit_stu_info_trigger(Student* ptr) {
    cout<<"请按照以下提示输入要修改的学生信息 (如果不需要修改该项的信息，请输入0)";
    string input_id[5];
    string edit_type[]={"学号:","姓名:","性别:","年龄:","班级:"};
    for(int i=0;i<5;i++) {
        cout<<endl<<edit_type[i];
        cin>>input_id[i];
    }

    ptr->editinfo(stoi(input_id[0]),input_id[1],input_id[2][0],stoi(input_id[3]),input_id[4]);

}

void inline edit_course_info_trigger(Course* ptr) {
    cout<<"请按照以下提示输入要修改的缺课记录信息 (如果不需要修改该项的信息，请输入0)";
    string input_id[5],type;
    string edit_type[]={"缺课日期:","节数序号:","课程名称:","学生姓名:","缺课类型:"};
    for(int i=0;i<5;i++) {
        if(i!=4) {
            cout<<endl<<edit_type[i];
            cin>>input_id[i];
        }
        else {
            cout<<endl<<edit_type[i];
            cin>>type;
            while(((type!="迟到"&&type!="早退")&&(type!="请假"&&type!="旷课"))&&type!="0") {
                cout<<"未支持的缺课类型！请重新输入:";
                cin>>type;
            }
            input_id[i]=type;
        }
    }

    ptr->editinfo(input_id[0],input_id[1],input_id[2],stoi(input_id[3]),input_id[4]);

}

//
//查找到对应信息后的操作选择面板
//
void select_after_search_1(string const& path,auto iterator) {
    cout<<"请选择接下来的操作:"<<endl;
    cout<<"[1]保存查找结果"<<endl<<"[2]对查找到的记录进行修改"<<endl<<"[3]继续查找"<<endl<<"请输入:";
    char input;
    cin>>input;
    if(input == '1') {
        create_trigger(path,iterator->second->getinfo());
    }
    else if(input == '2') {
        edit_stu_info_trigger(iterator->second);
    }
    else if(input == '3') {

    }
    else {
        cout<<"未支持的选择!程序将继续进行查找"<<endl;
    }
}

void select_after_search_2(string const& path,auto iterator) {
    cout<<"请选择接下来的操作:"<<endl;
    cout<<"[1]保存查找结果"<<endl<<"[2]对查找到的记录进行修改"<<endl<<"[3]继续查找"<<endl<<"请输入:";
    char input;
    cin>>input;
    if(input == '1') {
        create_trigger_2(path,iterator->second->getinfo());
    }
    else if(input == '2') {
        edit_course_info_trigger(iterator->second);
    }
    else if(input == '3') {

    }
    else {
        cout<<"未支持的选择!程序将继续进行查找"<<endl;
    }
}
//
//学生的查找函数，可以根据ID，姓名，年龄，班级和性别进行查找
//
template<typename T>
inline void search_stu_inf_trigger(void (*search)(T info),T info) {
    search(info);
}

inline void search_stu_inf_trigger(void (*search)(string const& info),string const& info) {
    search(info);
}

void inline search_stu_info_byID(int id) {
    auto iterator = students.find(id);
    if(iterator == students.end()) {
        cout<<"未找到学号对应的学生信息！"<<endl;
    }
    else {
        iterator->second->showinfo();
    }
    string path="C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_by_ID_"+to_string(id)+"_"+get_time()+".txt";

   select_after_search_1(path,iterator);
}

void inline search_stu_info_byName(string const &name) {
    auto iterator = students.begin();
    for(; iterator != students.end(); iterator++) {
        if(iterator->second->checkname() == name) {
            break;
        }
    }
    if(iterator==students.end()) {
        cout<<"未找到相应的学生信息！"<<endl;
    }
    else {
        iterator->second->showinfo();
    }

    string path="C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_by_Name_"+name+"_"+get_time()+".txt";
    select_after_search_1(path,iterator);
}

void inline search_stu_info_byGender(char gender) {
    auto iterator = students.begin();
    int cnt=0;
    for(; iterator != students.end(); iterator++) {
        if((iterator->second->checkgender())==gender) {
            iterator->second->showinfo();
            cnt++;

            string path="C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_by_Name_"+c_to_string(gender)+"_"+to_string(cnt)+"_"+get_time()+".txt";
            select_after_search_1(path,iterator);
        }
    }
    if(cnt==0) {
        cout<<"未找到相应的学生信息！"<<endl;
    }

}

void inline search_stu_info_byAge(int age) {
    auto iterator = students.begin();
    int cnt=0;
    for(;iterator!=students.end(); iterator++) {
        if((iterator->second->checkage())==age) {
            iterator->second->showinfo();
            cnt++;

            string path="C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_by_Name_"+to_string(age)+"_"+to_string(cnt)+"_"+get_time()+".txt";
            select_after_search_1(path,iterator);
        }
    }
    if(cnt==0) {
        cout<<"未找到对应的学生信息！"<<endl;
    }
}

void inline search_stu_info_byClass(string const & Class) {
    auto iterator = students.begin();
    int cnt=0;
    for(; iterator != students.end(); iterator++) {
        if((iterator->second->checkclass())==Class) {
            iterator->second->showinfo();
            cnt++;

            string path="C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_by_Name_"+Class+"_"+to_string(cnt)+"_"+get_time()+".txt";
            select_after_search_1(path,iterator);
        }
    }
    if(cnt==0) {
        cout<<"未找到对应的学生信息！"<<endl;
    }
}

//
//缺课记录的查找函数，可以根据ID，姓名，年龄，班级和性别进行查找
//1:按姓名查找 2:按学科查找 3:按日期查找 4:按课程序号查找 5:按缺课类型查找
void inline check_courses_info(string const& info,int n) {
    auto iterator = courses.begin();
    int cnt=0;
    string type[5]={"Name_","Subject_","Date_","Number_","Type_"};
    string path;
    for(; iterator != courses.end(); iterator++) {
        if((*iterator).second->check_info(n) == info) {
            cnt++;
            (*iterator).second->showinfo();
            path="C://Users//suzum//CLionProjects//CourseDesign//save//search_courses_by_"+type[n-1]+info+"_"+to_string(cnt)+"_"+get_time()+".txt";
            select_after_search_2(path,iterator);
        }
        else{}
    }

    if(cnt==0) {
        cout<<"未查询到相关记录！"<<endl;
    }
}

//
//统计函数
//
vector<Course*> inline statBySubject(const string& subject, bool(*compare)(const Course*, const Course*)) {
    vector<Course*> result;
    for (auto iterator = courses.begin(); iterator != courses.end(); iterator++) {
        if (iterator->second->check_subjuct() == subject) {
            result.push_back(iterator->second);
        }
    }

    cout<<"共统计到"<<result.size()<<"条记录。"<<endl;
    sort(result.begin(), result.end(), compare);
    return result;
}

vector<Course*> inline statByName(const string& name,bool(*compare)(const Course*, const Course*)) {
    vector<Course*> result;
    for (auto iterator = courses.begin(); iterator != courses.end(); iterator++) {
        if (iterator->second->check_name() == name) {
            result.push_back(iterator->second);
        }
    }

    cout<<"共统计到"<<result.size()<<"条记录。"<<endl;
    sort(result.begin(), result.end(), compare);
    return result;
}

bool inline compareByTime(Course* a, Course* b) {
    int yearA, monthA, dayA, yearB, monthB, dayB;
    stringstream ssA(a->check_date()), ssB(b->check_date());
    ssA >> yearA >> monthA >> dayA;
    ssB >> yearB >> monthB >> dayB;

    // 按照年/月/日的顺序比较
    if (yearA != yearB) {
        return yearA < yearB;
    } else if (monthA != monthB) {
        return monthA < monthB;
    } else {
        return dayA < dayB;
    }
}

vector<Course*> inline statByGroupAndCount(const vector<Course*>& courses, int groupType) {
    map<string, vector<Course*>> groups; // 根据学科名或者学生名把原来的vector分组

    // 扣1按学生名分组，扣2按课程名分组
    if (groupType == 1) {
        for (auto it : courses) {
            groups[(*it).check_name()].push_back(it);
        }
    } else if (groupType == 2) {
        for (auto course : courses) {
            groups[(*course).check_subjuct()].push_back(course);
        }
    } else {
        cerr << "不支持的选择类型!本次操作取消!" << endl;
        return {};
    }

    // 把分好的各小组放入新的vector中，用于排列
    vector<vector<Course*>> groupsVector;
    for (auto& pair : groups) {
        groupsVector.push_back(move(pair.second));
    }

    // 按次数（每个vector<Courses*>中的元素个数）排序
    sort(groupsVector.begin(), groupsVector.end(), [](const vector<Course*>& a, const vector<Course*>& b) {
        return a.size() > b.size();
    });

    // 把排列好的结果存入新的vector并返回。
    vector<Course*> result;
    for (const auto& newcourses : groupsVector) {
        result.insert(result.end(), newcourses.begin(), newcourses.end());
    }

    return result;
}

//
//文件操作相关函数
//
string inline get_time() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&time);

    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d_%H-%M-%S");

    return oss.str();
}
void inline cache_create(string const& path,string  const& input) {
    ofstream file (path,ios::out|ios::app);
    if(file.is_open()) {
        file<<input;
        file.close();
        cout<<"记录缓存成功！\n";
    }
    else {
        cerr<<"记录缓存时发生错误！"<<endl;
    }
}

void inline save_create(string const& path,string const& input) {
    ofstream file (path,ios::out|ios::app);
    if(file.is_open()) {
        file<<"-----------------------------------------"<<endl;
        file<<input;
        file.close();
        cout<<"记录已保存于"<<path<<endl;
    }
    else {
        cerr<<"记录保存时发生错误！"<<endl;
    }
}

inline void create_trigger(string const &path, string const &input) {
    cout<<"是否将查找到的记录保存为文件? (Y/N):";
    char confirm;
    cin>>confirm;
    if(confirm == 'N') {
        return ;
    }
    else {
        cout<<endl<<"请选择保存的方式：\n"<<"[1]保存为单个文件\n"<<"[2]保存于search_stu_all_result.txt中\n";
        create_select(path,"C://Users//suzum//CLionProjects//CourseDesign//save//search_stu_all_result.txt",input);
    }
}

inline void create_trigger_2(string const &path, string const &input) {
    cout<<"是否将查找到的记录保存为文件? (Y/N):";
    char confirm;
    cin>>confirm;
    if(confirm == 'N') {
        return ;
    }
    else {
        cout<<endl<<"请选择保存的方式：\n"<<"[1]保存为单个文件\n"<<"[2]保存于search_courses_all_result.txt中\n";
        create_select(path,"C://Users//suzum//CLionProjects//CourseDesign//save//search_courses_all_result.txt",input);
    }
}


void inline create_select(string const& path1, string const& path2, string const& input) {
    cout<<"请输入保存的方式：";
    char type;
    cin>>type;

    switch(type) {
        case '1': save_create(path1,input); break;
        case '2': save_create(path2,input); break;
        default: {
            cout<<"不受支持的类型! 是否重新输入? (Y/N):";
            cin>>type;
            if(type == 'N') {
                cout<<"结果未保存！";break;
            }
            else if(type == 'Y'){
                create_select(path1,path2,input);break;
            }
            else {
                cout<<"不受支持的输入！文件未保存！";break;
            }
        }
    }
}

void inline load_stu_info_from_records(const string& filename) {
    ifstream inputFile(filename);

        if (!inputFile.is_open()) {
        cerr << "打开文件失败！: " << filename << endl;
        return;
    }

    string line,key,content;
    while(getline(inputFile, line)) {
        if(line.empty()) {
            continue;
        }
        else if(line=="-----------------------------------------") {
            string structe[5];
            for(int i=0;i<5;i++) {
                getline(inputFile, line);
                key=line.substr(0,4);
                content=line.substr(6);
                structe[checkkey(key)]=content;
            }

            if(students.contains(stoi(structe[0]))) {
                cout<<"此记录中的学号与现有学号冲突，将不被保存！\n发生冲突的学号为:"<<structe[0]<<endl;
            }
            else {
                Student* ptr=new Student(stoi(structe[0]),structe[1],structe[2][0],stoi(structe[3]),structe[4]);
                students[stoi(structe[0])]=ptr;
            }
        }
        else {
            cout<<"读取到未知内容，返回以下读取结果："<<line<<endl;continue;
        }
    }
end_of_file:
    inputFile.close();
}

int inline checkkey(string const& key) {
    if(key=="学号"||key=="缺课日期") {
        return 0;
    }
    else if(key=="姓名"||key=="节数序号") {
        return 1;
    }
    else if(key=="性别"||key=="课程名称") {
        return 2;
    }
    else if(key=="年龄"||key=="学生姓名") {
        return 3;
    }
    else {
        return 4;
    }

}
#endif
