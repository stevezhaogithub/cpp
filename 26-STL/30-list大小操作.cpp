#include <iostream>
#include <list>
using namespace std;

void print_list(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    print_list(L1);

    if (L1.empty())
    {
        cout << "L1 为空！" << endl;
    }
    else
    {
        cout << "L1 不为空！" << endl;
        cout << "L1.size() = " << L1.size() << endl;
        L1.resize(10);
        cout << "L1.size() = " << L1.size() << endl;
        print_list(L1);
        L1.resize(20, 99999);
        print_list(L1);
        cout << "L1.size() = " << L1.size() << endl;
    }
}
int main()
{
    test01();
    return 0;
}