#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    int n, m, red_max, blue_max;
    vector<int> red;
    vector<int> blue;
    cin >> t;
    while(t--) {
        cin >> n;
        red_max=0;
        blue_max=0;
        red.push_back(0);
        blue.push_back(0);
        for(int i=1;i<=n;i++) {
            int x; cin>>x;
            red.push_back(x+red[i-1]);
            red_max = max(red_max, red[i]);
        }
        cin >> m;
        for(int i=1;i<=m;i++) {
            int x; cin>>x;
            blue.push_back(x+blue[i-1]);
            blue_max = max(blue_max, blue[i]);
        }
        cout << max(max(red_max, blue_max), max(0,red_max+blue_max)) << "\n";
        vector<int>().swap(red);
        vector<int>().swap(blue);
    }
    return 0;
}