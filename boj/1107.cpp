//너무풀기싫은문제
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    int minv = INT_MAX;

    cin >> n >> m;
    int tmp;
    for(int i=0;i<m;i++) {
        cin >> tmp;
        arr[tmp] = 0;
    }

    minv = min(minv, abs(100-n));
    if(arr[0]) minv = min(minv, n+1);

    for(int i=1;i<=1000000;i++) {
        int dig = (int)log10(i)+1;
        int pw=1;
        int flag = 1;
        while(pw<=dig) {
            int ppow = pow(10, pw-1);
            int tg = (i/ppow)%10;;
            if(arr[tg]==0) {
                flag = 0;
                break;
            }
            pw++;
        }
        if(flag) minv = min(minv, abs(n-i)+dig);
    }

    cout << minv;
    return 0;
}