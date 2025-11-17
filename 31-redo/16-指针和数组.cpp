#include <iostream>

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};

    // -------- 这三行代码要特别注意 --------
    int len = sizeof(nums) / sizeof(nums[0]);
    int *ptr_start = nums;
    int *ptr_end = nums + len;
    // -------- 这三行代码要特别注意 --------

    while (ptr_start != ptr_end)
    {
        std::cout << *ptr_start << std::endl;
        ptr_start++;
    }
    return 0;
}