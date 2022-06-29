//정구문제
#include <iostream>
#include <algorithm>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

int n, k;
vector<int> group;

void grouping(vector<int> *pv) {
    vector<int> tmp;
    int lastest = 0;

    for(int i : group) {
        if(lastest!=group[i]) {
            lastest = group[i];
            tmp.push_back(lastest);
        }
    }
    tmp.swap(*pv);
    return;
}

int dp(vector<int> pv) {
    int minV = INT_MAX, tmp, dpv;
    vector<int> ans;
    grouping(&pv);
    
    switch(pv.size()) {
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            for(int i=0;i<pv.size();i++) {
                tmp = pv[i];
                if(i!=0) { // left
                    pv[i] = pv[i-1];
                    dpv = dp(pv);
                    if(minV > dpv) {
                        minV = dpv;
                        ans.assign(pv.begin(), pv.end());
                    }
                }
                if(i!=pv.size()-1) {
                    pv[i] = pv[i+1];
                    dpv = dp(pv);
                    if(minV > dpv) {
                        minV = dpv;
                        ans.assign(pv.begin(), pv.end());
                    }
                }
                pv[i] = tmp;
            }
    }
    return 1+dp(ans);    
}

int solve() {
    return dp(group);
}

int main() {
    int t;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> t;
        group.push_back(t);
    }
    cout << solve();

    return 0;
}