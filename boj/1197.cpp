//1197
#include <iostream>
#include <vector>
#include <algorithm>
#define pp(x,y) make_pair(x, y)
#define for(i,n) for(int i=0;i<n;i++)
using namespace std;

class Edge {
public:
    pair<int, int> vertex;
    int dist;
    Edge(int x, int y, int dist) {
        this->vertex.first = x;
        this->vertex.second = y;
        this->dist = dist;
    }
    bool operator < (Edge &edge) {
        return this->dist < edge.dist;
    }
};

vector<Edge> input;
int *cycle_table, sum;
int v, e;

int parent(int x) {
    if(cycle_table[x] == x)
        return x;
    else {
        cycle_table[x] = parent(cycle_table[x]);
        return cycle_table[x];
    }
}

void union_p(int x, int y) {
    int xp, yp;
    xp = parent(x);
    yp = parent(y);
    if(xp < yp) cycle_table[yp] = xp;
    else cycle_table[xp] = yp;
    return;
}

bool isCycle(int x, int y) {
    if(parent(x) == parent(y))
        return true;
    return false;
}

/*void print_table() {
    for(i,v+1) {
        cout << cycle_table[i] << " ";
    }
    cout << "\n";
    return;
}*/

void kruskal() {
    for(i,input.size()) {
        if(!isCycle(input[i].vertex.first, input[i].vertex.second)) {
           // print_table();
            sum += input[i].dist;
            union_p(input[i].vertex.first, input[i].vertex.second);
        }
    }
}

int main() {
    cin >> v >> e;
    cycle_table = new int[v+1];
    for(i, e) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x>y) swap(x,y);
        input.push_back(Edge(x,y,z));
    } //input
    sort(input.begin(), input.end());

    for(i,v+1) {
        cycle_table[i] = i;
    }
    sum = 0;

    kruskal();
    
    cout << sum;

    return 0;
}