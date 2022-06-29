#include <iostream>
#include <algorithm>
#define pp(x,y) make_pair(x,y)
using namespace std;

int main() {
    int t, n, k, no;
    int* ground;
    pair<int, int>* block;
    cin >> t;
    while(t--) {
        no=0;
        cin >> n >> k;
        ground = new int[n+1];
        block = new pair<int, int>[n+1]; // lower bound, upper bound
        for(int i=1;i<=n;i++) {
            cin >> ground[i];
        }
        block[1] = pp(ground[1], ground[1]);
        for(int i=2;i<=n;i++) {
            int lower = max(block[i-1].first-(k-1), ground[i]);
            int upper = min(block[i-1].second+(k-1), ground[i]+k-1);
            if(lower <= upper) {
                block[i] = pp(lower, upper);
            }
            else {
                no=1;
                break;
            }
            //cout << block[i].first << " " << block[i].second << "\n";
        }
        if(block[n].first > ground[n] || block[n].second < ground[n]) no=1;

        if(no==1) cout << "NO\n";
        else cout << "YES\n";
        delete [] ground;
        delete [] block;
    }  
    return 0;
}