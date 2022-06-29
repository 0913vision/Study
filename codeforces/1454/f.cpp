#include <iostream>
#include <algorithm>
using namespace std;

int n, *s;

void input() {
    cin >> n;
    s = new int[n];
    for(int i=0;i<n;i++) {
        cin >> s[i];
    }
    return;
}

void solve() {
    
}

int main() {
    int t; cin>>t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}