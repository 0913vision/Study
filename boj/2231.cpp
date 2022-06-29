#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int digit = (int)log10((float)n) + 1;

    int var[7] = {0, };
    int ans = 0;

    for(int i=1;i<=n;i++) {
        var[0]++;
        for(int j=0;j<digit;j++) {
            if(var[j]>9) {
                var[j] = 0;
                var[j+1]++;
            }
        }
        ans = 0;
        for(int j=0;j<digit;j++) {
            ans += ((int)pow(10, j)+1) * var[j];
        }
        if(ans == n) {
            bool flag = false;
            for(int j=digit-1;j>=0;j--) {
                if(!flag && var[j]>0) {
                    flag = true;
                }
                if(flag) cout << var[j];
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "0\n";

    return 0;
}