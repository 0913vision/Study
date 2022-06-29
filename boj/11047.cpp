#include <iostream>
#include <algorithm>
#include <vector>
#define pp(x,y) make_pair(x, y)
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        coin.push_back(x);
    }
    int cnt = 0;
    for(vector<int>::reverse_iterator it=coin.rbegin();it<coin.rend();it++) {
        if(k>=(*it)) {
            cnt += k/(*it);
            k %= *it;
        }
    }
    cout << cnt << "\n";

    return 0;
}