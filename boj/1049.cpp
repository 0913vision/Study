#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int min_set=INT_MAX, min_one=INT_MAX;
    for(int i=0;i<m;i++) {
        int x, y; cin >> x >> y;
        min_set = min(min_set, x);
        min_one = min(min_one, y);
    }

    cout << (n/6)*(min(min_set, min_one*6)) + min(min_set, (n%6)*min_one);
    return 0;
}