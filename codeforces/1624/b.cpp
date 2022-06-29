#include <iostream>
using namespace std;

int main() {
    int t,a,b,c;
    bool ans;
    cin >> t;
    while(t--) {
        cin >> a>>b>>c;
        int m = (a+c)/2;
        if((a+c)%2==0 && m>=b && m%b==0) ans = true;
        else if(2*b-a>=c && (2*b-a)%c==0) ans = true;
        else if(2*b-c>=a && (2*b-c)%a==0) ans = true;
        else ans = false;

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}