/**
 *
 * 案例描述: 封装一个函数，利用冒泡排序，实现对数组的升序排序
 *
 */
#include <iostream>

// 特别注意：📢此处的形参 nums 无法在数组内部通过 sizeof(nums) / sizeof(nums[0]) 来计算数组长度，需要额外参数来提供数组长度
void sort_array(int *nums, int len);

int main()
{
    int numbers[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 19, 22, 88, 11};
    int N = sizeof(numbers) / sizeof(numbers[0]);
    sort_array(numbers, N);
    std::cout << "排序后:" << std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void sort_array(int *nums, int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - 1 - i; ++j)
        {
            // 升序排序
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}