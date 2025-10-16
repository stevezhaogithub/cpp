//
//
// #include <iostream>
//
//// 常量
// #define MAX_SIZE 100
// using namespace std;
//
// int main() {
//     cout << "Hello World!" << endl;
//     // 常量
//     const int day = 10;
//     int n = 100;
//     cout << "n = " << n << endl;
//
//     cout << "一周有：" << MAX_SIZE << "天。" << endl;
//
//     cout << sizeof(int) << endl;
//
//     cout << "=================" << endl;
//
//     cout << sizeof(long) << endl;
//
//     cout << sizeof(long long) << endl;
//
//     // system("pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;
//
// int main() {
//     //    char ch = 'A';
//     //
//     //    cout << ch << endl;
//     //
//     //    cout << sizeof(ch) << endl;
//     //
//     //    cout << sizeof(char) << endl;
//     //
//     //    cout << (int)ch << endl;
//
//     cout << "Hello World!" << endl;
//
//     cout << "哈喽，世界\n";
//
//     cout << "\aaa" << endl;
//
//     cout << "hello\t\t\tworld" << endl;
//     cout << "你好\t\t\t中国" << endl;
//     return 0;
// }

//// 字符串
//
// #include <iostream>
// #include <string>
// using namespace std;
//
// int main() {
//    string str = "hello world";
//    char text[] = "ABCD";
//    cout << str << endl;
//    cout << text << endl;
//    return 0;
//}

//// bool 类型
// #include <iostream>
// using namespace std;
//
// int main() {
//     bool flag = true;
//
//     cout << flag << endl;   // 1
//     flag = false;
//     cout << flag << endl;   // 0
//
//     cout << sizeof(bool) << endl;
//
//     return 0;
// }

//// 数据的输入
// #include <iostream>
// #include <string>
//
// using namespace std;
// int main() {
//     int a = 0;
//     cout << "请给整型变了 a 赋值：" << endl;
//     cin >> a;
//     cout << "a = " << a << endl;
//
//     cout << "请输入您的姓名：" << endl;
//     string username = "";
//     cin >> username;
//     cout << "您的名字是：" << username << endl;
// }

// #include <iostream>
// #include <string>
// using namespace std;
//
// int main() {
//     //    cout << "hello world!" << endl;
//     //    int n = 100;
//     //    cin >> n;
//     //    cout << "a = " << n << endl;
//     //
//     //    cout << 10 % 20 << endl;
//
//     cout << !(10 == 2) << endl;
//     return 0;
// }

///*
//    三目运算符
// */
// #include <iostream>
// #include <string>
// using namespace std;
//
// int main() {
//    int  a = 10, b = 20, c = 0;
//    c = a > b ? a : b;
//    cout << "c = " << c << endl;
//    return 0;
//}

// #include <iostream>
// #include <string>
// using namespace std;
//
// int main() {
//     int score;
//     cout << "请输入分数：" << endl;
//     cin >> score;
//     switch (score) {
//         case 1:
//             cout << "电影评分为：" << score << "很差了！";
//             break;
//         case 2:
//             cout << "电影评分为：" << score << "差！";
//             break;
//         case 3:
//             cout << "电影评分为：" << score << "一般！";
//             break;
//         case 4:
//             cout << "电影评分为：" << score << "良！";
//             break;
//         case 5:
//             cout << "电影评分为：" << score << "好！";
//             break;
//         default:
//             cout << "您的评分为：" << score << "不在合理评分范围内！";
//             break;
//     }
//
//     cout << endl;
//     return 0;
// }

//// 循环
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     //    for (int i = 0; i < 10; i++) {
//     //        cout << i << endl;
//     //    }
//
//     int num = 0;
//     while (num < 10) {
//         cout << num << endl;
//         num++;
//     }
//     return 0;
// }

//
//
//// 猜数字
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//
//     while (1) {
//
//         cout << "猜数字游戏开始!" << endl;
//         // 产生随机数
//         int number = rand() % 100 + 1;
//
//         while (1) {
//             int user_guess;
//             cout << "请输入您猜测的数字[1, 100]：";
//             cin >> user_guess;
//
//             if (number == user_guess) {
//                 cout << "猜对啦！" << endl;
//                 break;
//             } else if (user_guess < number) {
//                 cout << "您猜小了。" << endl;
//             } else {
//                 cout << "您猜大了。" << endl;
//             }
//         }
//     }
//     // 1. 生成随机数
//
//     // 2. 玩家进行猜测
//
//     // 3. 判断玩家猜测
//
//     // 4. 猜对：退出游戏；猜错：提示结果过大 or 过小，重新返回第 2 步
//
//     return 0;
// }

// ---------------------------------------------------------------

//// 水仙花数
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     int n = 100;
//     do {
//         // 个位、十位、百位
//         int ones_place, tens_place, hundreds_place;
//         ones_place = n % 10;
//         tens_place = n / 10 % 10;
//         hundreds_place = n / 100;
//
//         //        cout << ones_place << "-" << tens_place << "-" <<
//         //        hundreds_place << endl;
//         int total = ones_place * ones_place * ones_place +
//                     tens_place * tens_place * tens_place +
//                     hundreds_place * hundreds_place * hundreds_place;
//         if (total == n) {
//             cout << n << "是水仙花数。" << endl;
//         }
//         //        cout << total << "--" << n << endl;
//         n++;
//     } while (n <= 999);
//     return 0;
// }

//
// #include <iostream>
// #include <string>
// using namespace std;
//
// int checkNumber(int n) {
//
//    int ones_place = n % 10;
//    int tens_place = n / 10 % 10;
//    int hundreds_place = n / 100;
//    int sum = pow(ones_place, 3) + pow(tens_place, 3) + pow(hundreds_place,
//    3); return n == sum;
//}
//
// int main() {
//    for (int i = 100; i < 1000; i++) {
//        // 查找水仙花数
//        if (checkNumber(i)) {
//            cout << i << "是水仙花数。" << endl;
//        }
//    }
//    return 0;
//}

//// ------------------敲桌子
// #include <iostream>
// using namespace std;
// int checkSeven(int n) {
//     int ones_place = n % 10;
//     int tens_place = n / 10 % 10;
//
//     if (n % 7 == 0 || ones_place == 7 || tens_place == 7) {
//         return 1;
//     } else {
//         return 0;
//     }
// }
//
// int main() {
//     for (int i = 1; i <= 100; i++) {
//         if (checkSeven(i)) {
//             cout << i << " --- 敲桌子！" << endl;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
//
// int main() {
//     //    for (int i = 0 ; i < 10; i++) {
//     //        for (int j = 0; j < 10; j++) {
//     //            cout << "*";
//     //        }
//     //        cout << endl;
//     //    }
//
//     for (int i = 1; i <= 9; i++) {
//         for (int j = 1; j <= i; j++) {
//             cout << j << "*" << i << "=" << (i * j) << " ";
//             goto FLAG;
//         }
//         cout << endl;
//     }
//
//     FLAG:
//     cout << "到 flag 这里了。" << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//     int nums[10];
//     int numx[] = {1, 2, 3};
//     int numxa[2] = {10, 20};
//     cout << (long)nums << endl;
//
//     return 0;
// }

//// 数组逆序
// #include <iostream>
// using namespace std;
// int main() {
//     int nums[] = {1, 2, 3, 4, 5, 6, 7};
//     int len = sizeof(nums) / sizeof(int);
//
//     //    for (int i = 0; i < len / 2; i++) {
//     //        int temp = nums[i];
//     //        nums[i] = nums[len - i - 1];
//     //        nums[len - i - 1] = temp;
//     //    }
//     int start = 0;
//     int end = len - 1;
//     while (start < end) {
//         int temp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = temp;
//         start++;
//         end--;
//     }
//
//     for (int i = 0; i < len; i++) {
//         cout << nums[i] << "  ";
//     }
//     return 0;
// }

//
//// 冒泡排序
//
//// 冒泡排序
// #include <iostream>
// using namespace std;
//
// int main() {
//
//     int nums[] = {9, 3, 1, 5, 6, 2, 7};
//     int len = sizeof(nums) / sizeof(int);
//
//     for (int i = 0; i < len - 1; ++i)
//     {
//         for (int j = 0; j < len - i - 1; j++)
//         {
//             if (nums[j] > nums[j + 1])
//             {
//                 int temp = nums[j];
//                 nums[j] = nums[j + 1];
//                 nums[j + 1] = temp;
//             }
//         }
//     }
//
//     // 输出排序后的结果
//     for (int i = 0; i < len; ++i)
//     {
//         cout << nums[i] << " ";
//     }
//
//     cout << endl;
//
//     return 0;
// }

//// 二维数组
//
// #include <iostream>
// #include <string>
//
// using namespace std;
//
// int main() {
//
//    int nums[2][3] = {
//        {10, 20, 30},
//        {400, 500, 600}
//    };
//
//
//    cout << "行数：" << sizeof(nums) / sizeof(nums[0]) << endl;
//    cout << "列数：" << sizeof(nums[0]) / sizeof(nums[0][0]) << endl;
//
//    for (int i = 0; i < 2; ++i)
//    {
//        for (int j = 0; j < 3; ++j)
//        {
//            cout << nums[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

/*
 二维数组的几种定义方式：
 1、int nums[2][3];
 2、int nums[2][3] = {{1,2,3}, {4,5,6}};
 3、int nums[][3] = {1,2,3,4,5,6};
 4、int nums[2][3] = {1,2,3,4,5,6};


 */

//
//
//// 考试成绩统计
//
// #include <iostream>
// using namespace std;
// int main() {
//    int scores[3][3] = {{100, 100, 100}, {90, 50, 100}, {60, 70, 80}};
//
//    for (int i = 0; i < 3; i++) {
//        int sum = 0;
//        for (int j = 0; j < 3; j++) {
//            sum += scores[i][j];
//        }
//        cout << "总成绩为：" << sum << endl;
//    }
//
//    return 0;
//}

//// 值传递 和 引用传递
//
// #include <iostream>
// using namespace std;
//
// void swap_my(int a, int b) {}
//
// int main() {
//    int x = 100, y = 200;
//
//    cout << "交换前：x = " << x << ", y = " << y << endl;
//    swap_my(x, y);
//    cout << "交换后：x = " << x << ", y = " << y << endl;
//
//    return 0;
//}

// #include <iostream>
// #include "test.h"
//
// int main() {
//     int x = 10, y = 20;
//     swap_my(x, y);
//     return 0;
// }

//// ---------------- 指针 ---------------------------
//// 1、定义一个指针
//// 2、使用指针
//
// #include <iostream>
// using namespace std;
// int main() {
//    int a = 1110;
//    int *p;
//    p = &a;
//
//    cout << "a 的地址是：" << p << endl;
//
//    // 通过解引用的方式找到指针指向的内存
//    cout << "a 的值是：" << *p << endl;
//
//
//    cout << "指针的占用内存大小：" << sizeof(double *) << endl;
//
//
//    // 空指针
//    int *pot = NULL;
//
//    cout << "空指针：" << pot << endl;
//
//    cout << "访问空指针：" << *pot << endl;
//
//    // 野指针
//
//    return 0;
//}

//// ---------- 指针 和 数组
// #include <iostream>
// using namespace std;
// int main() {
//     int nums[3] = {1, 2, 3};
//     int size = sizeof(nums) / sizeof(int);
//     int *start = nums, *end;
//     end = start + size;
////    cout << *p << endl;
////    p++;
////    cout << *p << endl;
//
//
//    while (start != end) {
//        cout << *start << endl;
//        start++;
//    }
//    return 0;
//}

// #include <iostream>
// using namespace std;
// void swap_number(int *x, int *y) {
//     int n = *x;
//     *x = *y;
//     *y = n;
// }
// int main() {
//     int a = 10, b = 20;
//     swap_number(&a, &b);
//     cout << "a = " << a << ", b = " << b << endl;
//     return 0;
// }

//
//// --------- 指针、数组、函数
//
// #include <iostream>
// using namespace std;
// void bubbleSort(int *arr, int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//
// int main() {
//    int nums[] = {10, 1, 6, 5, 4, 99, 3, 7};
//    int len = sizeof(nums) / sizeof(int);
//    bubbleSort(nums, len);
//    // 循环输出数组内容
//    for (int i = 0; i < len; i++) {
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

// ------------------结构体------------------------

// #include <iostream>
// #include <string>
// using namespace std;
// struct student {
//     string name;
//     int age;
//     int score;
// } stu3;
// int main() {
//     struct student stu1;
//     stu1.name = "steve";
//     stu1.age = 18;
//     stu1.score = 90;
//
//     stu3.name = "";
//     int a = 100, b= 200;
//     int * const p = &a;
//     //const int * p = &a;
//     *p = 1000;
//     //p = &b;
//     cout << *p << endl;
//
//     cout << stu1.name << "-" << stu1.age << "-" << stu1.score << endl;
//     return 0;
// }

//// -------------------------- 结构体数组
// #include <iostream>
// #include <string>
// using namespace std;
// struct student {
//     string name;
//     int age;
//     int score;
// };
//
// struct teacher {
//     int id;
//     string name;
//     int age;
//     struct student stu;
// };
// int main() {
//
//     struct student stus[] = {
//         {"张三", 18, 90}, {"李四", 19, 91}, {"王五", 20, 92}};
//     int N = sizeof(stus) / sizeof(struct student);
//
//     for (int i = 0; i < N; i++) {
//         cout << stus[i].name << "-" << stus[i].age << "-" << stus[i].score
//              << endl;
//     }
//
//     // 结构体指针 ----------------
//
//     // 1. 创建结构体变量
//     struct student model = {"bob", 22, 99};
//     // 2. 创建指向结构体变量的结构体指针
//     struct student *p = &model;
//     // 3. 通过指针访问结构体变量中的数据
//     cout << p->name << p->age << p->score << endl;
//
//     // 结构体嵌套结构体 -------------------------
//     struct student zhangsan = {"zs", 23, 98};
//
//     //    struct teacher ls =  {
//     //        1001,
//     //        "lisi",
//     //        40,
//     //        zhangsan
//     //
//     //    };
//
//     struct teacher ls = {
//         1001,
//         "lisi",
//         40,
//         {"zs", 23, 98}
//     };
//
//     cout << ls.stu.name << endl;
//     return 0;
// }

//// ------------ 结构体中 const 的使用
//
// #include <iostream>
// #include <string>
// using namespace std;
//
// struct student {
//    string name;
//    int age;
//    int score;
//};
//
// void printStudent(const student *stu) {
//    stu->name = "lisi";
//    cout << "姓名：" << stu->name << endl;
//}
//
// int main() {
//    struct student model = {
//        "张三",
//        18,
//        90
//    };
//
//    printStudent(&model);
//
//    cout << model.name << endl;
//    return 0;
//}

// #include <iostream>
// #include <string>
// #include <ctime>
// using namespace std;
//
// struct student {
//     string sName;
//     int score;
// };
//
// struct teacher {
//     string tName;
//     struct student stus[5];
// };
//
//// 为老师数组分配数据
// void allocate_space(struct teacher tArray[], int N) {
//     string nameSeed = "ABCDE";
//
//     for (int i = 0; i < N; i++) {
//         // 设置老师的姓名
//         tArray[i].tName = "teacher_";
//         tArray[i].tName += nameSeed[i];
//
//         // 设置老师对应的学生
//         for (int s = 0; s < 5; s++) {
//             // 设置学生姓名
//             tArray[i].stus[s].sName = "student_";
//             tArray[i].stus[s].sName += nameSeed[i];
//             tArray[i].stus[s].sName += nameSeed[s];
//
//             // 设置学生成绩
//             // 生成一个 [40, 100] 的随机数
//             tArray[i].stus[s].score = rand() % 61 + 40;
//         }
//     }
// }
//
// void printInfo(struct teacher *tArray, int N) {
//     for (int i = 0; i < N; i++) {
//         cout << "老师姓名：" << tArray[i].tName  <<endl;
//         for (int j = 0; j < 5; j++) {
//             cout << "\t\t 学生姓名：" << tArray[i].stus[j].sName <<
//             "\t成绩："
//                  << tArray[i].stus[j].score << endl;
//         }
//     }
// }
//
// int main() {
//
//     // 设置随机数种子
//     srand((unsigned int)time(NULL));
//
//
//     // 声明一个用来存储老师的数组
//     struct teacher teachers[3];
//     int n = sizeof(teachers) / sizeof(struct teacher);
//     // 为老师数组分配内容
//     allocate_space(teachers, n);
//
//     // 输出所有信息
//     printInfo(teachers, n);
//
//     return 0;
// }

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct hero {
    string name;
    int age;
    string gender;
};

// 加载所有英雄数据
void load_data(struct hero *heroes, int N) {
    string names[] = {"刘备", "关羽", "张飞", "赵云", "貂蝉"};
    string sex[] = {"男", "女"};
    for (int i = 0; i < N; i++) {
        heroes[i].name = names[i];
        heroes[i].age = rand() % 101 + 20;
        heroes[i].gender = sex[rand() % 2];
    }
}

// 输出所有英雄信息
void printInfo(struct hero heroes[], int N) {
    for (int i = 0; i < N; i++) {
        cout << heroes[i].name << " - " << heroes[i].age << " - "
             << heroes[i].gender << endl;
    }
}

// 按照年龄进行冒泡排序
void bubbleSort(struct hero *heroes, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (heroes[j].age > heroes[j + 1].age) {
                struct hero temp = heroes[j];
                heroes[j] = heroes[j + 1];
                heroes[j + 1] = temp;
            }
        }
    }
}

int main() {

    // 设置随机数种子
    srand((unsigned int)time(NULL));
    struct hero heroes[5];
    load_data(heroes, 5);
    bubbleSort(heroes, 5);
    printInfo(heroes, 5);
    return 0;
}
