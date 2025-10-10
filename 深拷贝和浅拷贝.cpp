
#include <iostream>
#include <string>
using namespace std;


class Person {
public:
	Person() {
		cout << "默认构造函数" << endl;
	}

	Person(int age, int height) {
		m_age = age;
		m_height = new int(height);
		cout << "带参数的构造函数" << endl;
	}

	// 自己编写深拷贝
	Person(const Person &p) {
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		cout << "调用了自己实现的拷贝构造函数---深拷贝。" << endl;
	}

	~Person() {
		cout << "析构函数" << endl;
		// 在析构函数中销毁堆区分配的内存
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
	}
	int m_age;
	int * m_height;
};


void test01() {
	Person p1(18, 160);
	cout << "p1的年龄为：" << p1.m_age << " 身高为：" << *p1.m_height << endl;

	// 浅拷贝，会把 p1 中 m_height 指向的地址拷贝到 p2 的 m_height 中 
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << " 身高为：" << *p2.m_height << endl;


	/*
		注意：
		在执行析构函数的时候，p2 的析构函数先执行，先把 m_height 内存释放
		然后 p1 再执行析构函数，此时，m_height 的内存已经释放了，所以再次释放就报错了

		浅拷贝带来的问题：堆区的内存重复释放

		解决浅拷贝带来的问题：用深拷贝解决。
		- 自己实现一个拷贝构造函数，实现深拷贝
	*/
}


int main() {

	test01();
	return 0;
}