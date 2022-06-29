#include <iostream>
#include <cmath>
using namespace std;

int prime[101010];
int flag;

void cal(int t) {
    if(t<0) t*=-1;
    int range = (int)sqrt(t);
    for(int i=2;i<=range;i++) {
        while(t%i==0) {
            prime[i] += flag;
            t /= i;
        }
    }
    if(t!=1) prime[t] += flag;
    return;
}

void solve() {
    for(int i=2;i<=100000;i++) {
        if(prime[i] < 0) {
            cout << "toothpaste";
            return;
        }
    }
    cout << "mint chocolate";
    return;
}

int main() {
    int n, x;
    char b;
    for(int i=0;i<=100000;i++) prime[i] = 0;
    cin >> n >> x;
    if(x==0) {
        cout << "mint chocolate";
        return 0;
    }
    flag = 1;
    cal(x);
    for(int i=0;i<n-1;i++) {
        cin >> b >> x;
        if(b=='*' && x==0) {
            cout << "mint chocolate";
            return 0;
        }
        if(b == '*') flag = 1;
        else flag = -1;
        cal(x);
    }
    solve();
    
    return 0;
}