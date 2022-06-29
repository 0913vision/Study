#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, tmp, max;
    cin >> n >> m;
    vector<int> card;
    
    for(int i=0;i<n;i++) {
        cin >> tmp;
        card.push_back(tmp);
    }
    max = -1;
    for(int k=2;k<n;k++) {
        for(int j=1;j<k;j++) {
            for(int i=0;i<j;i++) {
                tmp = card[i] + card[j] + card[k];
                if(tmp > max && tmp <= m) max = tmp;
            }
        }
    }
    cout << max << "\n";

    return 0;
}