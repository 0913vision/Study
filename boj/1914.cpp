#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve(int n, int init, int dest, int tmp) {
    if(n==1) {
        cout << init << " " << dest << "\n";
        return;
    }
    solve(n-1, init, tmp, dest);
    cout << init << " " << dest << "\n";
    solve(n-1, tmp, dest, init);
    return;
}

int main() {
    int n; cin >> n;
    string ans= to_string(pow(2,n));
    ans[ans.find('.')-1] -= 1;
    cout << ans.substr(0,ans.find('.')) << "\n";
    if(n<=20) solve(n,1,3,2);
    return 0;
}