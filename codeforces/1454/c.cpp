#include <iostream>
#include <climits>
using namespace std;

int *sq;
int *cut;
int n;

void input() {
    cin >> n;
    sq = new int[n];
    cut = new int[n+1];
    for(int i=1;i<=n;i++) {
        cut[i] = -1;
    }
    for(int i=0;i<n;i++) {
        cin >> sq[i];
        if(i==0) {
            cut[sq[i]] = 0;
        }
        else if(i!=0 && sq[i]!=sq[0]) {
            cut[sq[i]] = 1;
        }
    }
    return;
}

void solve() {
    int ans = INT_MAX;
    for(int i=0;i<n-1;i++) {
        if(sq[i] != sq[i+1]) {
            cut[sq[i]]++;
        }
    }
    for(int i=1;i<=n;i++) {
        if(cut[i]>=0) {
            ans = min(ans, cut[i]);
        }
    }
    cout << ans << "\n";
    delete [] sq;
    delete [] cut;
    return;
}

int main() {
    int t; cin>>t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}