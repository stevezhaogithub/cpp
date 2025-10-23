#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class ZSteveArray
{
public:
    // 构造函数
    ZSteveArray(int _capacity)
    {
        this->m_capacity = _capacity;
        this->m_size = 0;
        this->ptr_addr = new T[this->m_capacity];
        cout << "有参 - 构造函数" << endl;
    }

    // 拷贝构造函数（实现深拷贝）
    ZSteveArray(const ZSteveArray &arr)
    {
        cout << "拷贝 - 构造函数" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // 要实现深拷贝，不是浅拷贝
        this->ptr_addr = new T[arr.m_capacity];
        // 循环拷贝
        for (int i = 0; i < this->m_size; i++)
        {
            this->ptr_addr[i] = arr.ptr_addr[i];
        }
    }

    // 重载 operator= 防止浅拷贝问题
    ZSteveArray &operator=(const ZSteveArray &arr)
    {
        cout << "operator= 调用" << endl;
        // 先判断原来堆区是否有数据，如果有数据先释放
        if (this->ptr_addr != NULL)
        {
            delete[] this->ptr_addr;
            this->ptr_addr = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        // --- 执行拷贝操作 ---
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // 要实现深拷贝，不是浅拷贝
        this->ptr_addr = new T[arr.m_capacity];
        // 循环拷贝
        for (int i = 0; i < this->m_size; i++)
        {
            this->ptr_addr[i] = arr.ptr_addr[i];
        }

        // 返回自身
        return *this;
    }

    // 尾插法
    void push_tail(const T &_data)
    {
        // 将 _data 插入到数组中
        if (this->m_size == this->m_capacity)
        {
            cout << "数组已满！" << endl;
            return;
        }

        // 向数组的最后一个位置插入
        this->ptr_addr[this->m_size] = _data;
        this->m_size++; // 更新数组大小
    }

    // 尾删法
    void pop_tail()
    {
        if (this->m_size == 0)
        {
            return;
        }
        // 让用户无法访问最后一个元素（逻辑上删除）
        this->m_size--;
    }

    // 通过下标访问数组
    T &operator[](int _index)
    {
        if (_index >= 0 && _index < this->m_size)
        {
            return this->ptr_addr[_index];
        }
        throw out_of_range("索引不在合法范围内：" + to_string(_index));
    }

    // 返回数组容量
    int get_capacity()
    {
        return this->m_capacity;
    }

    // 返回数组大小
    int get_size()
    {
        return this->m_size;
    }

    // 析构函数
    ~ZSteveArray()
    {
        cout << "析构函数" << endl;
        if (this->ptr_addr != NULL)
        {
            // 1. 不二级指针，不需要循环释放每个对象
            // 2. 释放数组内存
            delete[] this->ptr_addr;
            this->ptr_addr = NULL;
        }
    }

private:
    T *ptr_addr;    // 数组地址
    int m_capacity; // 数组容量
    int m_size;     // 当前数组的大小
};
