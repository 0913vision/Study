#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int x; cin>>x;
        for(int i=2;i<=x;i++) {
            cout << i << " ";
        }
        cout << 1 << "\n";
    }
    return 0;
}