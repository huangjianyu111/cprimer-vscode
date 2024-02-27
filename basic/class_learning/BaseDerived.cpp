#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
public:
	virtual void f(){ cout << "Base::f" << endl; }
	virtual void g(){ cout << "Base::g" << endl; }
public:
	int base_m1 , base_m2;
// private:
//     int base_m3, base_m4;
};
 
class Derived: public Base{
public:
    // void f() override { cout << "Derived::f" << endl; }
    // void g() override { cout << "Derived::g" << endl; }
	virtual void f1(){ cout << "Derived::f1" << endl; }
	virtual void g1(){ cout << "Derived::g1" << endl; }
public:
	int derived_m1 , derived_m2;
};

void play() {
    typedef void (*pFunc)();		//定义 void func(); 类型的函数指针类型
    Base base_obj;

    printf("base_obj addr:%p\n", &base_obj);
    
    void **p_base = (void **)&base_obj;
    void **vptr_base = (void **)*p_base;
    
    pFunc pf = (pFunc)vptr_base[0];    //虚函数 vf 的函数指针
    pFunc pg = (pFunc)vptr_base[1];    //虚函数 vg 的函数指针
    pf();
    pg();



    Derived derived_obj;
    printf("derived_obj addr:%p\n", &derived_obj);
    
    void **p_derived = (void **)&derived_obj;
    void **vptr_derived = (void **)*p_derived;
    
    pFunc f = (pFunc)vptr_derived[0];    //继承自父类的虚函数 vf 的函数指针
    pFunc g = (pFunc)vptr_derived[1];    //继承自父类的虚函数 vg 的函数指针
    pFunc pf1 = (pFunc)vptr_derived[2];   //虚函数 vf1 的函数指针
    pFunc pg1 = (pFunc)vptr_derived[3];   //虚函数 vg1 的函数指针
    f();
    g();
    pf1();
    pg1();

}

int main() {
    printf("sizeof Base:%d\n", sizeof(Base));
    printf("sizeof Derived:%d\n", sizeof(Derived));//base 的private也会影响 Derived的内存分配
    Derived child;
    printf("对象地址 -----------------\n");
    printf("child addr:%p \n", &child);

    printf("成员变量地址 -----------------\n");
    printf("base_m1 \t addr:%p \n", &child.base_m1);
    printf("base_m2 \t addr:%p \n", &child.base_m2);
    printf("derived_m1 \t addr:%p \n", &child.derived_m1);
    printf("derived_m2 \t addr:%p \n", &child.derived_m2);

    printf("成员函数地址 -----------------\n");
    printf("f \t addr:%p \n", &Derived::f);
    printf("g \t addr:%p \n", &Derived::g);
    printf("f1 \t addr:%p \n", &Derived::f1);
    printf("g1 \t addr:%p \n", &Derived::g1);

    play();

    return 0;
}