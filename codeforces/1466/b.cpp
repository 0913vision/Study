#include <iostream>
using namespace std;

int *notes, n;

void input() {
    cin >> n;
    notes = new int[2*n+2];
    for(int i=0;i<=2*n+1;i++) {
        notes[i] = 0;
    }
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        notes[x]++;
    }
    return;
}

int solve() {
    for(int i=1;i<=2*n;i++) {
        if(notes[i]>1 && notes[i+1]<=1) {
            notes[i]--;
            notes[i+1]++;
        }
    }
    int ret=0;
    for(int i=1;i<=2*n+1;i++) {
        if(notes[i]>0) ret++;
    }
    delete [] notes;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) {
        input();
        cout << solve() << "\n";
    }
    return 0;
}