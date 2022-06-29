#include <iostream>
#define MAX 301
using namespace std;

int n;
int arr[MAX]; // value of each stair
int dp[MAX]; // value of max.

void Solve() {
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2]+arr[3]);

    for(int i=4;i<=n;i++) {
        dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
    }

    cout << dp[n];
}

int main() {
    //input
    Solve();
    //end
}