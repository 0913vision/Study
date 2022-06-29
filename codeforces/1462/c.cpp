#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int x; cin >> x;
        int ans = 0;
        int arr[10] = {0, }; int i=9;
        while(x>0) {
            for(i=9;i>0;i--) {
                if(x-i>=0 && arr[i]==0) {
                    x -= i;
                    arr[i]++;
                    break;
                }
            }
            if(i==0 && x!=0) {
                break;
            }
        }
        if(x!=0) {
            cout << -1 << "\n";
        }
        else {
            for(int i=1;i<=9;i++) {
                if(arr[i]==1) 
                    cout << i;
            }
            cout << "\n";
        }
    }
    return 0;
}