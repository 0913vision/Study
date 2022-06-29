#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;

ll arr[101010], n;
ll dp[101010];
ll ans = -1;

void input() {
    cin >> n;
    for(int i=0;i<n;i++) { // O(n)
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for(int i=1;i<n;i++) { // O(n)
        dp[i] = arr[i] + dp[i-1];
    }
    return;
}

void solve(int l, int r) {
    if(l>r) return;
    if(l==r) {
        ans = max(ans, arr[l]*arr[l]);
        return;
    }
    int m = (l+r)/2;
    solve(l, m);
    solve(m+1, r);
    int left=m; int right=m;
    int lv, rv;
    ll cur_min = arr[m];
    while(left!=l || right!=r) {
        if(left>l) lv = arr[left-1];
        else lv = -1;
        if(right<r) rv = arr[right+1];
        else rv = -1;
        if(lv<rv) {
            right++;
            cur_min = min(cur_min, arr[right]);
        }
        else {
            left--;
            cur_min = min(cur_min, arr[left]);
        }
        ans = max(ans, (dp[right]-dp[left]+arr[left])*cur_min);
    }
    return;
}

int main() {
    input();
    solve(0, n-1);
    cout << ans;
    return 0;
}