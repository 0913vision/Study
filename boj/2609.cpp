#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    int x, t;
    x = a*b;

    if(a<b) {
        swap(a, b);
    }

    while(b!=0) {
        t = a;
        a = b;
        b = t%b;
    }
    cout << a << "\n" << x/a << "\n";

    return 0;
}