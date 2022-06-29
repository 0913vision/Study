#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> books;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        books.push_back(x);
    }
    if(n==0) {
        cout << 0;
        return 0;
    }
    int box_cnt=1;
    int box_r = m;
    for(int i=0;i<n;i++) {
        if(books[i] <= box_r)
            box_r -= books[i];
        else {
            box_cnt++;
            box_r = m-books[i];
        }
    }
    cout << box_cnt;
    return 0;
}