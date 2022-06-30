#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[9];
    int sum=0;
    for(int i=0;i<9;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int ii=0, jj=1;
    while(1) {
        if(sum - arr[ii] - arr[jj] == 100) break;
        else {
            if(jj==8) {
                ii++;
                jj = ii+1;
            }
            else {
                jj++;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<9;i++) {
        if(i!=ii && i!=jj) {
            ans.push_back(arr[i]);
        }
    }

    sort(ans.begin(), ans.end());

    for(int i=0;i<7;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}