#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

ll cal[40] = {0, }; // a를 2^i번 곱한 값을 c로 나눈 나머지.
ll a, b, c;

double log2(double n) {
    return log(n)/log(2);
}

ll solve(ll x) {
    if(x==0) return 1;
    if(x==1) return cal[0];
    int t = (int)log2(x);
    int p = pow(2,t);
    if(x==b) {
        for(int i=1;i<=t;i++) {
            cal[i] = (cal[i-1]*cal[i-1])%c;
        }
    }
    x -= p; //x+p -> 원래 x, x+2^t
    int ret = (cal[t]*solve(x))%c; // b를 2^t번 곱한것 * b를 x번 곱한것 = b를 (2^t+x)번 곱한것
    return ret;
}

int main() {
    cin >> a >> b >> c;
    cal[0] = a%c;
    cout << solve(b);
    return 0;
}