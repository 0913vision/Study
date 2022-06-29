#include <iostream>
using namespace std;

int main() {
    int t, n, *arr;
    cin >> t;
    while(t--) {
        cin >> n;
        int M = 0;
        int m = INT32_MAX;
        arr = new int[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            M = max(M, arr[i]);
            m = min(m, arr[i]);
        }
        cout << M-m << "\n";
        delete arr;
    }
    return 0;
}