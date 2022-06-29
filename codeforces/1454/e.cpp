#include <iostream>
#include <vector>
using namespace std;

int n;
int* visited;
vector<int> *vertex;

void input() {
    cin >> n;
    vertex = new vector<int>[n+1];
    visited = new int[n+1];
    for(int i=1;i<=n;i++) {
        visited[i] = 0;
    }
    
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    return;
}

void solve() {
    
}

int main() {
    int t; cin >> t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}