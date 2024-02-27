#include <iostream>
#include <stdio.h>

using namespace std;

class BaseA{
public:
    virtual void vf(){ cout << "virtual BaseA::vf" << endl; }
public:
	int base_m1;
};
 
class BaseB{
public:
    virtual void vg(){ cout << "virtual BaseB::vg" << endl; }
public:
	int base_m2;
};

class BaseC{
public:
     void vk(){ cout << " BaseC::vk" << endl; }
public:
	int base_m3;
};

 
class Derived: public BaseA, public BaseB, public BaseC{
public:
    virtual void vf(){ cout << "virtual Derived::vf" << endl; }
    virtual void vg(){ cout << "virtual Derived::vg" << endl; }
public:
	int derived_m4;
};

int main() {
    printf("sizeof BaseA:%d\n", sizeof(BaseA));
    printf("sizeof BaseB:%d\n", sizeof(BaseB));
    printf("sizeof BaseC:%d\n", sizeof(BaseC));
    printf("sizeof Derived:%d\n", sizeof(Derived));

    Derived child;
    printf("对象地址 -----------------\n");
    printf("child addr:%p \n", &child);

    printf("成员变量地址 -----------------\n");
    printf("base_m1 \t addr:%p \n", &child.base_m1);
    printf("base_m2 \t addr:%p \n", &child.base_m2);
    printf("base_m3 \t addr:%p \n", &child.base_m3);
    printf("derived_m4 \t addr:%p \n", &child.derived_m4);

    printf("成员函数地址 -----------------\n");
    printf("BaseA vf \t addr:%p \n", &BaseA::vf);
    printf("BaseB vg \t addr:%p \n", &BaseB::vg);
    printf("Derived vf \t addr:%p \n", &Derived::vf);
    printf("Derived vg \t addr:%p \n", &Derived::vg);


    child.vf();
    child.vg();

    return 0;
}