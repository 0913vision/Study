#include <iostream>
#include <algorithm>
#include <vector>
#define s(i) i.first
#define e(i) i.second
#define pp(x,y) make_pair(x, y)
#define for(i,n) for(int i=0;i<n;i++)
using namespace std;

int n;
vector<pair<int, int>> meet;

bool func(pair<int, int> a, pair<int, int> b) {
    if(e(a) != e(b)) {
        return e(a) < e(b);
    }
    return s(a) < s(b);
}

void meetSort() {
    sort(meet.begin(), meet.end(), func);
    return;
}

int main() {
    cin >> n;
    for(i, n) {
        int a, b;
        cin >> a >> b;
        meet.push_back(pp(a, b));
    }
    meetSort();
    int cnt=0, final=0;
    for(i, n) {
        if(final <= s(meet[i])) {
            final = e(meet[i]);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}