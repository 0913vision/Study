#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int dig = log10(n)+1;
    ull ans = 0;

    if(dig==1) {
        cout << n;
        return 0;
    }

    for(int i=1;i<dig;i++) {
        ans += (ull)pow(10, i-1) * 9 * i;
    }

    ans += (n - (ull)pow(10,dig-1) + 1) * dig;

    cout << ans;

    return 0;
}