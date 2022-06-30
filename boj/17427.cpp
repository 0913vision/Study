#include <iostream>
using namespace std;

typedef unsigned long long ull;
ull f[1010101] = {0,};
ull g[1010101] = {0,};

int main() {   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=1;i<=1000000;i++) {
        for(int j=i;j<=1000000;j+=i) {
            f[j] += i;
        }
    }
    g[1] = f[1];
    for(int i=2;i<=1000000;i++) {
        g[i] = g[i-1] + f[i];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << g[n] << "\n";
    }
    
    return 0;
}
