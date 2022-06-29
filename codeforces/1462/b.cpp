#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    string ans = "2020";
    while(t--) {
        int n; cin >> n;
        string input; cin >> input;
        int i; int found=0; int l=0; int r=-1; int ans_idx=0; int no=0; int yes=0;
        if(input.size()==4) {
            //cout << "size fit!\n";
            if(input == ans) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            for(i=0;i<=4;i++) {
                //cout << "0~" << i << " + " << n+i-4 << "~" << n-1 << " = " << input.substr(0,i) + input.substr(n+i-4, 4-i) << "\n";
                if(ans == input.substr(0,i) + input.substr(n+i-4, 4-i)) {
                    cout << "YES\n";
                    break;
                }
            }
            if(i==5) {
                cout << "NO\n";
            }
        }
    }
    return 0;
}