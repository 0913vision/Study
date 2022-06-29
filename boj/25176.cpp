#include <iostream>
using namespace std;

unsigned long long int facto(int n) {
    if(n==1) return n;
    else return facto(n-1)*n;
}

int main() {
    int n;
    cin >> n;
    cout << facto(n);
    return 0;
}