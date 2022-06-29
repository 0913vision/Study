#include <iostream>
#include <vector>
using namespace std;

int diameter = 0;
int diameter_point = 0;
int *visit;
vector<pair<int, int>> vertex[10101];
int flag = 1;

void dfs(int target, int value) {
    if(visit[target] == flag)
        return;
    visit[target] = flag;
    if(diameter < value) {
        diameter = value;
        diameter_point = target;
    }

    for(int i=0;i<vertex[target].size();i++) {
        dfs(vertex[target][i].first, value+vertex[target][i].second);
    }
    return;
}

int main() {
    int n, u, v, e;
    cin >> n;
    visit = new int[n+1];
    for(int i=1;i<=n;i++)
        visit[i] = 0;
    
    for(int i=1;i<=n-1;i++) {
        cin >> u >> v >> e;
        vertex[u].push_back(make_pair(v, e));
        vertex[v].push_back(make_pair(u, e));
    } //data input

    dfs(1, 0);
    flag = 2;
    diameter = 0;
    dfs(diameter_point, 0);

    cout << diameter;

    return 0;
}