#include <iostream>
#include <string>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        string same, diff;
        unsigned long long int n, x, y;
        cin >> n >> x >> y;

        if(x%2 == y%2) {
            same = "Alice"; diff = "Bob";
        }
        else {
            same = "Bob"; diff = "Alice";
        }

        unsigned long long int tmp, odd=0;
        for(unsigned long long int i=0;i<n;i++) {
            cin >> tmp;
            if(tmp%2) odd++;
        }
        
        if(odd%2) cout << diff;
        else cout << same;

        cout << "\n";
    }
    return 0;
}