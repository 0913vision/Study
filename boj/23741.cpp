#include <iostream>
#include <set>
using namespace std;

typedef set<int>::iterator si;

int n, m, x, y;
set<int> *adj;
set<int> last;
set<int> current;

void bfs(int node, int movable) {
    last.insert(node);
    for(int i=movable;i>0;i--) {
        for(si it=last.begin();it!=last.end();it++) {
            for(si it2=adj[*it].begin();it2!=adj[*it].end();it2++) {
                current.insert(*it2);
            }
        }
        last.swap(current);
        current.clear();
    }
}

int main() {
    
    cin >> n >> m >> x >> y;

    adj = new set<int>[n+1];

    for(int i=0;i<m;i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }

    if(adj[x].empty()) {
        cout << "-1\n";
        return 0;
    }

    bfs(x, y);

    for(si it=last.begin();it!=last.end();it++) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}