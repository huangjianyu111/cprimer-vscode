#include <stdio.h>
#include <list>
#include <string>
#include <memory>

class Student {
public:
    int id;
    std::string name;
};

int main() {
    std::shared_ptr<Student> student1(new Student());
    student1->id = 1;
    student1->name = "123";

    Student* sPointer1;
    sPointer1 = student1.get();
    printf("student id:%d, name:%s\n", sPointer1->id, sPointer1->name);

    sPointer1 = nullptr;

    if (student1)
    printf("student id:%d, name:%s\n", student1->id, student1->name);

    return 0;
}