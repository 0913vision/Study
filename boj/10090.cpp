#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int *s, *tmp, n;
ll cnt;

void solve(ll l, ll r) {
    ll m;
    if(l>=r) return;
    else if(l==r-1 && s[l] > s[r]) {
        cnt++;
        swap(s[l], s[r]);
        return;
    }
    else {
        m = (l+r)/2;
        solve(l, m); // m-l+1개
        solve(m+1, r); // r-m개
        ll x=l, y=m+1;
        while(x<=m && y<=r) {
            ll t=y;
            while(t<=r && s[x] > s[t]) {
                t++;
            }
            if(t-y>0) {
                cnt += (m-x+1)*(t-y);
                y=t;
            }
            else x++;
        }
        ll t=0;x=l;y=m+1;
        while(x<=m && y<=r) {
            if(s[x] < s[y]) {
                tmp[t] = s[x];
                t++; x++;
            }
            else {
                tmp[t] = s[y];
                t++; y++;
            }
        }
        if(y==r+1) {
            for(int i=x;i<=m;i++) {
                tmp[t++] = s[i];
            }
        }
        else if(x==m+1) {
            for(int i=y;i<=r;i++) {
                tmp[t++] = s[i];
            }
        }
        for(int i=l;i<l+t;i++) {
            s[i] = tmp[i-l];
        }
        return;
    }
}

void input() {
    cin>>n;
    s = new int[n+1];
    tmp = new int[n+1];
    for(int i=1;i<=n;i++) {
        cin >> s[i];
    }
    cnt = 0;
    solve(1, n);
    cout << cnt;
    delete [] s;
    delete [] tmp;
    return;
}

int main() {
    input();
    return 0;
}