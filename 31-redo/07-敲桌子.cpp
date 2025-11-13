#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        int ones = i % 10;
        int tens = i / 10;
        if (i % 7 == 0 || ones == 7 || tens == 7)
        {
            cout << "\n----------敲桌子----------" << endl;
        }
        else
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}