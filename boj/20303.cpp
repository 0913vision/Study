//knapsack problem
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2147483647
using namespace std;

int n, m, k;
vector<int> candy;
vector<int> *friends;
int *visited;
int *groupCandy;
int *groupNumber;
int **dp;

void dfs(int node, int group) {
    visited[node] = 1;
    groupCandy[group] += candy[node];
    groupNumber[group]++;
    for(int i=0;i<friends[node].size();i++) {
        int next = friends[node][i];
        if(visited[next] == 0)
            dfs(next, group);
    }
    return;
}

int main() {
    cin >> n >> m >> k;
    friends = new vector<int>[n+1];
    visited = new int[n+1]; // 0 : dfs yet // k(!=0) : top friend number.
    groupCandy = new int[n]; // i번째 그룹의 사람수
    groupNumber = new int[n]; // i번째 그룹의 캔디양
    candy.push_back(0);
    for(int i=1;i<=n;i++) {
        int x; cin >> x; candy.push_back(x);
        visited[i] = 0;
        groupCandy[i-1] = 0;
        groupNumber[i-1] = 0;
    }
    for(int i=0;i<m;i++) {
        int x, y; cin >> x >> y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }
    int g=0;
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            dfs(i, g); // node, group number
            g++;
        }
    }

    dp = new int*[g+1];
    for(int i=0;i<=g;i++) {
        dp[i] = new int[k+1];
        for(int j=0;j<=k;j++) {
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=g;i++) {
        for(int j=0;j<=k;j++) {
            if(groupNumber[i-1] < j) dp[i][j] = max(groupCandy[i-1] + dp[i-1][j-groupNumber[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[g][k];
}