#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int n, i, j;
    cin >> n >> input;

    for(i=0;i<n-4;i++) {
        for(j=i;j<i+4;j++) {
            //cout << i << j << input[j] - input[j+1] << " ";
            if(input[j] - input[j+1] != 1 && input[j] - input[j+1] != -1) {
                break;
            }
        }
        if(j==i+4) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}