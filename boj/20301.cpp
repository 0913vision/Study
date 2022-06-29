#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int n, k, m, tk, tm, flag;
deque<int> q;
vector<int> ans;

void josep() {
    if(tk==k) {
        tk=1;
        if(flag==1) {
            ans.push_back(q.front());
            q.pop_front();
        }
        else {
            ans.push_back(q.back());
            q.pop_back();
        }
        tm++;
        if(tm==m) {
            tm=0;
            flag *= -1;
        }
        return;
    }
    if(flag == 1) {
        q.push_back(q.front());
        q.pop_front();
        tk++;
    }
    else {
        q.push_front(q.back());
        q.pop_back();
        tk++;
    }
}

int main() {
    cin >> n >> k >> m;
    for(int i=1;i<=n;i++) {
        q.push_back(i);
    }
    tk=1; tm=0; flag=1;
    while(!q.empty())
        josep();
    for(int i=0;i<n;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}