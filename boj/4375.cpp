#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        unsigned long long int t = 1;
        int ans = 1;
        while(t%n != 0) {
            t = ((t*10)%n + 1)%n;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}