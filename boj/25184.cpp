#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int half = n/2;

    for(int i=half;i>=1;i--) {
        cout << i << " " << i+half << " ";
    }
    if(n%2==1) {
        cout << n;
    }

    return 0;
}