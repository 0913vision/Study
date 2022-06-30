#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int minN, maxN, t;
    minN = 1010101;
    maxN = -1;
    for(int i=0;i<n;i++) {
        cin >> t;
        minN = min(minN, t);
        maxN = max(maxN, t);
    }
    cout << maxN*minN;
    return 0;
}