#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define pp(x,y,z) make_tuple(x, y, z)
using namespace std;

int main() {
    int n, k, l;
    vector<tuple<int, int, int>> join;
    cin >> n >> k >> l;
    for(int i=0;i<n;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x+y+z>=k && x>=l && y>=l && z>=l)
            join.push_back(pp(x,y,z));           
    }
    cout << join.size() << "\n";
    for(int i=0;i<join.size();i++) {
        int x, y, z;
        tie(x,y,z) = join[i];
        cout << x << " " << y << " " << z << " ";
    }
    return 0;
}