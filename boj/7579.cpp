#include <iostream>
#include <algorithm>
#include <memory.h>
#define INT_MAX 2147483647
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, min_cost=0;
    int *use, *cost, **dp;
    cin >> n >> m;
    use = new int[n];
    cost = new int[n];
    dp = new int*[n]; // ?
    for(int i=0;i<n;i++) {
        dp[i] = new int[n*100];
        memset(dp[i], 0, n*100*sizeof(int));
    }

    for(int i=0;i<n;i++)
        cin >> use[i];
    for(int i=0;i<n;i++) {
        cin >> cost[i];
        min_cost += cost[i];
    }
    dp[0][cost[0]] = use[0];

    for(int i=1;i<n;i++) {
        for(int j=0;j<=n*100;j++) {
            if(j-cost[i]>=0) { // it can disabled
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+use[i]); // case : disable
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]); // case : able
            // i를 켠 것과 끈 것 중에서 용량 확보가 더 많이 되는 것을 선택한다.
            if(dp[i][j] >= m)
                min_cost = min(min_cost, j);
        }
    }

    cout << min_cost;
    
    return 0;
}