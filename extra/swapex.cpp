#include <iostream>
using namespace std;

void swapValue(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

int main() {
    int a, b;
    a = 3;
    b = 4;
    swapValue(a, b);
    
    cout << a <<", "<< b << endl;
    return 0;
}