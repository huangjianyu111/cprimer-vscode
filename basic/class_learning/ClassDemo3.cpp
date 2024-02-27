
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Name1{
public:
	void f(){ cout << "Name1::f" << endl; }
	void g(){ cout << "Name1::g" << endl; }
	void h(){ cout << "Name1::h" << endl; }
	void k(){
		int a = 0;
		printf("a \t addr: 0x%p\n", &a);
	}
public:
	int m1, m2;
};

class Name2{
public:
	void f(){ cout << "Name2::f" << endl; }
	void g(){ cout << "Name2::g" << endl; }
	virtual void vh(){ cout << "Name2::vh" << endl; }
	virtual void vk(){ cout << "Name2::vk" << endl; }
public:
	int m1 , m2;
};

void play02(){
	typedef void (*pFunc)();		//定义 void func(); 类型的函数指针类型
	Name2 obj;
 
	cout << "\n成员函数地址 -------------" << endl;
	printf("vh() \t addr: 0x%p\n", &Name2::vh);
	printf("vk() \t addr: 0x%p\n", &Name2::vk);
 
	printf("虚函数表中第一个虚函数的函数指针 addr: 0x%p\n", *((int64_t*)*(int64_t*)&obj+0));
	printf("虚函数表中第二个虚函数的函数指针 addr: 0x%p\n", *((int64_t*)*(int64_t*)&obj+1));
 
	pFunc ph = (pFunc)*((int64_t*)*(int64_t*)&obj+0);
	pFunc pk = (pFunc)*((int64_t*)*(int64_t*)&obj+1);
 
	printf("函数指针调用结果：\n");
	ph();
	pk();
}

int main() {
    // printf("sizeof(Name1) : %d \n", sizeof(Name1));//8

    printf("sizeof(Name2) : %d \n", sizeof(Name2));//8

    Name2 obj;
    cout << "对象地址 -------------" << endl;
    printf("obj \t addr: 0x%p\n", &obj);
    
    cout << "\n成员变量地址 -------------" << endl;
    printf("m1 \t addr: 0x%p\n", &obj.m1);
    printf("m2 \t addr: 0x%p\n", &obj.m2);

    cout << "\n成员函数地址 -------------" << endl;
    printf("f() \t addr: 0x%p\n", &Name2::f); //成员函数f一定要有函数体的定义，下同
    printf("g() \t addr: 0x%p\n", &Name2::g);
    printf("vh() \t addr: 0x%p\n", &Name2::vh);
    printf("vk() \t addr: 0x%p\n", &Name2::vk);

    play02();

    return 0;
}