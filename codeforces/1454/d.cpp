#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;

int* prime;
ll x;

void input() {
    cin >> x;
    return;
}

void solve() {
    ll N = x;
    int freq = 0;
    int freq_n = 0;
    int upper = sqrt(x)+1;
    vector<ll> ans;
    prime = new int[upper+1];
    for(int i=0;i<=upper;i++) {
        prime[i] = 0;
    }
    int i=2;
    while(i<=upper && x!=1) {
        if(x%i==0) {
            prime[i]++;
            if(freq < prime[i]) {
                freq = prime[i];
                freq_n = i;
            }
            x/=i;
        }
        else i++;
    }
    while(freq_n!=0 && (N/freq_n)%freq_n==0) {
        ans.push_back(freq_n);
        N /= freq_n;
    }
    if(N!=1) {
        ans.push_back(N);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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