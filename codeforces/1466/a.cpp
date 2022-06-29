#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> tree;
int *area;

void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        tree.push_back(x);
    }
    area = new int[tree.back()+1];
    for(int i=0;i<=tree.back();i++) {
        area[i] = 0;
    }
}

int solve() {
    int ret = 0;
    for(int i=0;i<tree.size();i++) {
        for(int j=i+1;j<tree.size();j++) {
            if(area[tree[j]-tree[i]]==0) {
                ret++;
                area[tree[j]-tree[i]] = 1;
            }
        }
    }
    delete [] area;
    vector<int>().swap(tree);
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        input();
        cout << solve() << "\n";
    }
    return 0;
}