#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long int ll;

bool cmp(int a, int b) {return a>b;}

int main() {
    int n;
    ll score=0, negScore=0, posScore=0;
    int posNum = 0;
    cin >> n;
    vector<ll> neg;
    FOR(i,n) {
        int tmp;
        cin >> tmp;
        if(tmp>=0) {
            posScore += (ll)tmp;
            posNum++;
        }
        else {
            neg.push_back((ll)tmp);
            negScore += tmp;
        }
    }

    sort(neg.begin(), neg.end(), cmp);

    for(vector<ll>::iterator it=neg.begin();it!=neg.end();it++) {
        if((posScore+(*it))*(posNum+1) + (negScore-(*it)) > (posScore*posNum+negScore)) {
            posScore += *it;
            posNum++;
            negScore -= *it;
        }
        else break;
    }
    cout << posScore*posNum + negScore << "\n";

    return 0;
}