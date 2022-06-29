//정구
#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

int main() {
    int n, k;
    int *jungu;
    int **dp;
    int cost;
    cin >> n >> k;

    jungu = new int[n];
    dp = new int*[n];
    for(int i=0;i<n;i++) {
        cin >> jungu[i];
        dp[i] = new int[n];
        dp[i][i] = 0;
    }
    for(int i=0;i<n-1;i++) {
        if(jungu[i] == jungu[i+1]) 
            dp[i][i+1] = 0;
        else
            dp[i][i+1] = 1;
        //cout << "dp[" << i << "][" << i+1 << "] = " << dp[i][i+1] << "\n";
    }
    for(int l=3;l<=n;l++) {
        for(int i=0;i<n-l+1;i++) {
            dp[i][i+l-1] = INT_MAX;
            for(int j=i;j<i+l-1;j++) { // i~j and j+1~i+l-1
                if(jungu[i] == jungu[j+1])
                    cost = 0;
                else
                    cost = 1;
                
                dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][j]+dp[j+1][i+l-1]+cost);
            }
            //cout << "dp[" << i << "][" << i+l-1 << "] = " << dp[i][i+l-1] << "\n";
        }
    }
    cout << dp[0][n-1];

    return 0;
}