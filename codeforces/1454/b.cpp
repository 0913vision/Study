#include <iostream>
using namespace std;

int *unique;
int *input;
int n;

void f_input() {
    cin >> n;
    input = new int[n+1]; // i번째 사람의 입력
    unique = new int[n+1]; // i번이 유일한지 (유일하다면 사람을, 유일하지 않다면 -1, 입력 안했다면 0)
    for(int i=0;i<=n;i++) {
        input[i] = 0;
        unique[i] = 0;
    }
    for(int i=1;i<=n;i++) {
        cin >> input[i]; 
        if(unique[input[i]]==0) {
            unique[input[i]] = i;
        }
        else if(unique[input[i]]>0) {
            unique[input[i]] = -1;
        }
    }
    return;
}

void solve() {
    int ans=-1;
    for(int i=1;i<=n;i++) {
        if(unique[i] > 0) {
            ans = unique[i];
            break;
        }
    }
    cout << ans << "\n";
    delete [] unique;
    delete [] input;
    return;
}

int main() {
    int t; cin >> t;
    while(t--) {
        f_input();
        solve();
    }
    return 0;
}