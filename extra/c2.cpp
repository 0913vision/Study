#include <iostream>
using namespace std;

typedef long long int ll;

ll C(int n, int r) {
    ll **arr = new ll*[n+1];
    for(int i=0;i<=n;i++) {
        arr[i] = new ll[r+1];
    }
    for(int i=0;i<=n;i++) {
        int t = min(i,r);
        for(int j=0;j<=t;j++) {
            if(j==i || j==0) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
    return arr[n][r];
}

int main() {
    int n, r;
    cin >> n >> r;
    cout << C(n, r);
    return 0;
}