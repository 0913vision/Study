#include <iostream>
#include <string>
using namespace std;

bool isPalin(string arr, int n) {
    for(int i=0;i<n;i++) {
        if(arr[i] != arr[n-1-i]) return false;
    }
    return true;
}

int solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k==0) return 1;
    bool b = isPalin(s, n);
    if(b) return 1;
    else return 2;
}

int main () {
    int t;
    cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}