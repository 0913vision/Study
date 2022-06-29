#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, t1, t2;
    vector<int> *edge;

    cin >> n >> m;

    edge = new vector<int>[n+1];

    for(int i=0;i<m;i++) {
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }

    bool *visited = new bool[n+1];
    fill_n(visited, n+1, false);
    queue<int> q;
    q.push(1);

    int ans=0;

    while(!q.empty()) {
        t1 = q.front();
        q.pop();
        if(!visited[t1]) {
            visited[t1] = true;
            ans++;
            for(vector<int>::iterator i=edge[t1].begin();i!=edge[t1].end();i++) {
                if(!visited[*i]) {
                    q.push(*i);
                }
            }
        }
    }

    cout << ans-1;

    return 0;
}