#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int ans = (m+k-3) % n; // 0~n-1
    if(ans<=0) ans+=n;

    cout << ans;

    return 0;
}