#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double *input;
    double maxv = 0;
    int n; cin >> n;
    input = new double[n];
    for(int i=0;i<n;i++) {
        cin >> input[i];
    }
    maxv = input[0];
    for(int i=1;i<n;i++) {
        if(input[i-1]*input[i] > input[i]) {
            input[i] = input[i-1]*input[i];
        }
        if(maxv < input[i]) maxv = input[i];
    }
    cout<<fixed;
    cout.precision(3);
    cout << maxv;

    return 0;
}