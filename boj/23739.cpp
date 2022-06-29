#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *time = new int[n];
    int *rest = new int[n];
    for(int i=0;i<n;i++) {
        cin >> time[i];
        rest[i] = time[i];
    }
    
    int res=30;
    int i=0;
    while(1) {
        if(i==n) break;
        else if(rest[i] < res) {
            res -= rest[i];
            rest[i] = 0;
        }
        else if(rest[i] == res) {
            rest[i] = 0;
            res = 30;
        }
        else if(rest[i] > res) {
            rest[i] -= res;
            res = 30;
        }
        i++;
    }
    res = 0;
    for(int i=0;i<n;i++) {
        if(rest[i] <= time[i]/2) res++;
    }
    cout << res;

    return 0;
}