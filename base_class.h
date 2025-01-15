//
// Created by suzum on 25-1-9.
//

#ifndef BASE_CLASS_H
#define BASE_CLASS_H
#include <string>
class Base {
public:
    Base(){}
    virtual ~Base(){}
    virtual void showinfo()=0;
    virtual std::string getinfo()=0;
};


#endif //BASE_CLASS_H
