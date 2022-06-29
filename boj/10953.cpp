#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        string input;
        cin >> input;
        cout << input[0]-'0'+input[2]-'0' << "\n";
    }
    return 0;
}