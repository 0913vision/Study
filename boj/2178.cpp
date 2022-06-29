#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int n, m, **dist;
    cin >> n >> m;
    string maze[n];
    dist = new int*[n];
    for(int i=0;i<n;i++) {
        dist[i] = new int[m];
        for(int j=0;j<m;j++) {
            dist[i][j] = 0x7fffffff;
        }
    }

    for(int i=0;i<n;i++) {
        cin >> maze[i];
    }

    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    int x=0, y=0, mydist=0;
    queue<tuple<int, int, int>> q; // x, y, my_dist
    tuple<int, int, int> current;

    q.push(make_tuple(0,0,1));

    while(!q.empty()) {
        current = q.front();
        q.pop();
        tie(x, y, mydist) = current;
        //cout << "current = " << y << " " << x << " " << mydist << endl;
        if(dist[y][x] > mydist) {
            dist[y][x] = mydist;
            for(int i=0;i<4;i++) {
                if(y+dy[i] >= 0 && y+dy[i] < n && x+dx[i] >= 0 && x+dx[i] < m) {
                    //cout << maze[y+d[i]].at(x+d[j]) << endl;
                    if(maze[y+dy[i]].at(x+dx[i]) == '1') {
                        //cout << "push << "<<y+dy[i]<< " " <<x+dx[i] << " " << mydist+1 << endl;
                        q.push(make_tuple(x+dx[i], y+dy[i], mydist+1));
                    }
                }
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";

    return 0;
}