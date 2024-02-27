#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

class SalesData {
public:
    explicit SalesData(int count) { mCount = count; }
    ~SalesData() {};

private:
    int mCount;

};

// template<typename T>
// void print(T& container) {
//     []()->{
//         for (auto& ele:container) {
//             cout << ele << ", " << endl;
//         }
//         cout << endl;
//     };
// }


int main() {
    std::list<std::string> names;
    std::vector<const char*> newNames{"hjy", "ttc"};

    // names = newNames;// 类型不匹配
    names.assign(newNames.begin(), newNames.end());

    for (auto& name:names) {
        std::cout << name << std::endl;
    }

    std::cout << names.max_size() << std::endl;

    std::vector<const char*> newNames2{"hjy"};
    std::vector<const char*> newNames3{"hjy", "ttc"};
    std::cout << "newNames == newNames2 : " << (newNames == newNames2) << std::endl;//0
    std::cout << "newNames == newNames3 : " << (newNames == newNames3) << std::endl;//1

    

    std::vector<int> v1 = {1, 3, 5, 7, 9, 12};
    std::vector<int> v2 = {1, 3, 9};
    std::vector<int> v3 = {1, 3, 5, 7};
    std::vector<int> v4 = {1, 3, 5, 7, 9, 12};

    std::cout << "v1 < v2 : " <<  (v1 < v2) << std::endl;//1
    std::cout << "v1 < v3 : " <<  (v1 < v3) << std::endl;//0
    std::cout << "v1 == v4 : " <<  (v1 == v4) << std::endl;//1
    std::cout << "v3 == v4 : " <<  (v3 == v4) << std::endl;//0
    std::cout << "v3 < v4 : " <<  (v3 < v4) << std::endl;//1


    // 使用 emplace
    std::vector<SalesData> vec;
    // 在元素类型，不允许自动类型转换的情况下，或报错 没有匹配额 push_back版本
    // vec.push_back(1);

    // emplace 类型的 成员函数，会将参数传递给元素类型的构造函数，创建一个临时的 SalesData 实例
    vec.emplace_back(1);

    // 改变容器大小
    // 
    list<int> listDemo(10,1);
    // print(listDemo);
    for (const auto&ele:listDemo) {
        cout << ele << ", ";
    }
    cout << endl;

    cout << "listDemo size : " << listDemo.size() << endl;
    listDemo.resize(15);//将5个值为0的元素添加到尾部
    for (const auto&ele:listDemo) {
        cout << ele << ", ";
    }
    cout << endl;

    listDemo.resize(25,-1);//将10个值为-1的元素添加到尾部
    for (const auto&ele:listDemo) {
        cout << ele << ", ";
    }
    cout << endl;

    listDemo.resize(5);//将删除尾部20个元素
    for (const auto&ele:listDemo) {
        cout << ele << ", ";
    }
    cout << endl;

    return 0;
}