#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int n;
int** maze;
int cur = 2;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void bfs(pair<int, int> v) {
    int tx, ty;
    queue<pair<int, int>> q;
    q.push(v);

    pair<int, int> curVertex;
    while(!q.empty()) {
        curVertex = q.front();
        q.pop();
        tie(ty, tx) = curVertex;
        if(maze[ty][tx] == 1) {
            maze[ty][tx] = cur;

            for(int i=0;i<4;i++) {
                if(ty+dy[i]>=0 && ty+dy[i]<n && tx+dx[i]>=0 && tx+dx[i]<n && maze[ty+dy[i]][tx+dx[i]] == 1) {
                    q.push(make_pair(ty+dy[i], tx+dx[i]));
                }
            }
        }
        
    }
    return;
}

int main() {
    int *house;
    cin >> n;
    string *input = new string[n];
    maze = new int*[n];
    house = new int[n*n];
    for(int i=0;i<n;i++) {
        cin >> input[i];
        maze[i] = new int[n];
        for(int j=0;j<n;j++) {
            if(input[i].at(j)=='1') maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }

    for(int i=0;i<n*n;i++) {
        house[i] = 0;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(maze[i][j] == 1) {
                bfs(make_pair(i, j));
                cur++;
            }
        }
    }
    
    /*for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }
    cout << "\n";*/

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(maze[i][j]!=0)
                house[maze[i][j]]++;
        }
    }

    sort(house, house+n*n);

    cout << cur-2 << "\n";
    for(int i=0;i<n*n;i++) {
        if(house[i]>0) cout << house[i] << "\n";
    }

    return 0;
}