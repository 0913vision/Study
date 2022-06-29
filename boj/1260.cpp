#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
priority_queue<int, vector<int>, greater<int>> *edge, *edge2;
bool *visited;

void dfs(int);
void bfs(int);

int main() {
    cin >> n >> m >> v;
    edge = new priority_queue<int, vector<int>, greater<int>>[n+1];
    edge2 = new priority_queue<int, vector<int>, greater<int>>[n+1];
    visited = new bool[n+1];
    for(int i=0;i<n+1;i++) {
        visited[i] = false;
    }
    int v1, v2;

    for(int i=0;i<m;i++) {
        cin >> v1 >> v2;
        edge[v1].push(v2);
        edge[v2].push(v1);
        edge2[v1].push(v2);
        edge2[v2].push(v1);
    }

    dfs(v);
    cout << "\n";
    delete[] visited;
    visited = new bool[n+1];
    for(int i=0;i<n+1;i++) {
        visited[i] = false;
    }
    bfs(v);
    cout << "\n";

    return 0;
}

void dfs(int v) {
    int next;
    cout << v << " ";
    visited[v] = true;
    while(!edge[v].empty()) {
        next = edge[v].top();
        edge[v].pop();
        if(!visited[next]) {
            dfs(next);
        }
    }
    return;
}

void bfs(int v) {
    queue<int> q;
    int cur, adj;

    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << " ";
        
        while(!edge2[cur].empty()) {
            adj = edge2[cur].top();
            edge2[cur].pop();
            if(!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}