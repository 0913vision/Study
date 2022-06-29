#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <tuple>
#define pp(x,y,z) make_tuple(x, y, z)
using namespace std;

int main() {
    int n;
    cin >> n;
    set<tuple<int, int, int>> room;
    priority_queue<pair<int, int>> adjNum; // <개수, 방번호>
    set<tuple<int, int, int>>::iterator it;
    set<tuple<int, int, int>>::iterator it2; 
    int** adj = new int*[n];
    int* flag = new int[n];
    for(int i=0;i<n;i++) {
        flag[i] = -1;
        adj[i] = new int[n];
        for(int j=0;j<n;j++) {
            if(i==j) adj[i][j]=1;
            else adj[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        room.insert(pp(x, y, z));
    }
    int i;
    for(it=room.begin();it!=room.end();it++) { // n^2
        i = distance(room.begin(), it);
        int x, y, z;
        tie(x,y,z) = *it;
        it2 = room.find(pp(x-1,y,z));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
        it2 = room.find(pp(x+1,y,z));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
        it2 = room.find(pp(x,y-1,z));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
        it2 = room.find(pp(x,y+1,z));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
        it2 = room.find(pp(x,y,z-1));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
        it2 = room.find(pp(x,y,z+1));
        if(it2 != room.end()) {
            adj[i][distance(room.begin(), it2)] = 1;
        }
    }
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<n;j++) {
            cout << adj[i][j] << " ";
            cnt += adj[i][j];
        }
        cout << "\n";
        adjNum.push(make_pair(cnt, i));
    }
    for(int i=0;i<n;i++) {
        cout << adjNum.top().second << " has " << adjNum.top().first << " adj room.\n";
        adjNum.pop();
    }
    int target_flag = 0;
    

    return 0;
}
