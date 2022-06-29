#include <iostream>
using namespace std;

typedef long long int ll;

ll C(int n, int r) {
    if(r==n || r==0) return 1;
    else return C(n-1,r-1)+C(n-1,r);
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << C(n, r);
    return 0;
}