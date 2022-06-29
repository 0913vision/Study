#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q = n / 18;
    int r = n % 18;

    if(r==0) cout << 2*q;
    else if(r<=9) cout << 2*q+1;
    else if(r%2==0) cout << 2*q+2;
    else cout << 2*q+3;

    return 0;
}