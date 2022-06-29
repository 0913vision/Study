#include <iostream>
using namespace std;

long long int fibonacci(int n) {
    long long int* arr = new long long int[n+1];
    arr[1] = 0;
    arr[2] = 1;
    for(int i=3;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}