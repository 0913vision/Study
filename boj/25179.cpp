#include <iostream>
using namespace std;

int main() {
    unsigned long long int n, m, r;
    cin >> n >> m;
    if(n==1) {
        cout << "Can't win";
        return 0;
    }
    r = (n-1)%(m+1);
    if(n<=m || r>0) {
        cout << "Can win";
        return 0;
    }
    cout << "Can't win";
    return 0;
}