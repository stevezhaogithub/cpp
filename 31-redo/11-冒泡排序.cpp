#include <iostream>

void bubble_sort()
{
    int nums[] = {10, 8, 90, 24, 81, 6, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);

    // 冒泡排序
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - 1 - i; ++j)
        {
            int temp;
            if (nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < len; ++i)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    bubble_sort();
    return 0;
}