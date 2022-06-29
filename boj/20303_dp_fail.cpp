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
int **dp_number;

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
    dp = new int*[g];
    dp_number = new int*[g];
    for(int i=0;i<g;i++) {
        dp[i] = new int[2];
        dp_number[i] = new int[2];
        dp_number[i][0] = dp_number[i][1] = dp[i][0] = dp[i][1] = 0;
    }

    if(groupNumber[0] < k) {
        dp[0][1] = groupCandy[0];
        dp_number[0][1] = groupNumber[0];
    }
    else
        dp[0][1] = 0;

    for(int i=1;i<g;i++) {
        int bin, bnin, bin_p, bnin_p;

        if(dp[i-1][0] >= dp[i-1][1]) {
            dp[i][0] = dp[i-1][0];
            dp_number[i][0] = dp_number[i-1][0];
        }
        else {
            dp[i][0] = dp[i-1][1];
            dp_number[i][0] = dp_number[i-1][1];
        }
        if(groupNumber[i] > k) {
            dp[i][1] = 0;
        }
            

        bin_p = dp_number[i-1][1] + groupNumber[i];
        bnin_p = dp_number[i-1][0] + groupNumber[i]; // bin_p > bnin_p
        if(bin_p < k) {
            bin = dp[i-1][1] + groupCandy[i];
        }
        else {
            bin = 0;
        }
        if(bnin_p < k) {
            bnin = dp[i-1][0] + groupCandy[i];
        }
        else {
            bnin = 0;
        }
        if(bin>0 && bnin>0) { // 인원수가 이전거를 넣어도되고 안넣어도됨
            if(bin <= bnin) {
                dp[i][1] = bnin + groupCandy[i];
                dp_number[i][1] = bnin_p;
            }
            else {
                dp[i][1] = bin + groupCandy[i];
                dp_number[i][1] = bin_p;
            }
        }
        else if(bnin>0) {
            dp[i][1] = bnin;
            dp_number[i][1] = bnin_p;
        }
        else {
            dp[i][1] = 0; //impossible
        }
    }
    cout << max(dp[g-1][0], dp[g-1][1]);

    return 0;
}
// dp로 풀면 최상의 해를 못구한다.