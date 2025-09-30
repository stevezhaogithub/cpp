#include <iostream>
#include <string>
using namespace std;

int add(int a, int b = 200, int c = 300) { return a + b + c; }

int main() {

    int ret1 = add(10, 20, 30);

    int ret2 = add(100);

    cout << "ret1 = " << ret1 << endl;
    cout << "ret2 = " << ret2 << endl;
    return 0;
}
