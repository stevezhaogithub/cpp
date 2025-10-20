// 利用函数模板封装一个排序函数，可对不同的数据类型进行排序
// 排序规则从小到大，排序算法为选择排序

#include <iostream>
using namespace std;

// 交换数据：函数模板
template <class T>
void swapping(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 打印输出：函数模板
template <class T>
void printing(T data[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            cout << data[i] << endl;
        }
        else
        {
            cout << data[i] << ", ";
        }
    }
}

// 排序：函数模板
template <class T>
void sorting(T data[], int N)
{
    for (int i = 0; i < N; i++)
    {
        // 假设最小值的下标是 i
        int minIdx = i;
        // 通过循环找出当前最小的
        for (int j = i + 1; j < N; j++)
        {
            if (data[j] < data[minIdx])
            {
                minIdx = j;
            }
        }
        // 交换
        if (minIdx != i)
        {
            swapping(data[i], data[minIdx]);
        }
    }
}

void test01()
{
    char text[] = "zxbdauiogf";
    int n = sizeof(text) / sizeof(char);
    sorting(text, n);
    printing(text, n);
}

void test02()
{
    int nums[] = {8, 1, 9, 3, 0, 33, 88, 22, 11};
    int n = sizeof(nums) / sizeof(int);
    sorting(nums, n);
    printing(nums, n);
}

int main()
{
    // test01();
    test02();
    return 0;
}
