#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, *color, **dp;
    cin >> n >> k;
    color = new int[n+1];
    dp = new int*[n];

    if((n+1)/2 < k) { // 가우스함수
        cout << "0";
        return 0;
    }

    for(int i=0;i<n+1;i++)
        dp[i] = new int[k+1];

    for(int i=1;i<=n;i++)
        dp[i][1] = i; // 하나 고르는 경우의 수는 i개
    
    for(int i=4;i<=n;i++) {
        for(int j=2;j<=k;j++) {
            dp[i][j] = dp[i-2][j-1] + dp[i-1][j]; // I번째 고르기 + 안고르기
            dp[i][j] %= 1000000003;
        }
    }

    cout << dp[n][k];

    return 0;
}