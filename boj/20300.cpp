#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, i;
    vector<long long int> muc;
    cin >> n;
    for(i=0;i<n;i++) {
        long long int x; cin>>x;
        muc.push_back(x);
    }
    if(n==1) {
        cout << muc[0];
        return 0;
    }
    sort(muc.begin(), muc.end());
    long long int max;
    if(n%2==0) {
        max = -1;
    }
    else {
        max = muc[n-1];
        n--;
    }
    for(i=0;i<n/2;i++) {
        long long int target = muc[i] + muc[n-1-i];
        if(target > max) max = target;
    }
    cout << max;

    return 0;
}