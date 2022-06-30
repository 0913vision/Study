#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n = 5457;
    int dig = (int)log10(n)+1;
    int pw=1;
    int flag = 1;
    while(pw<=dig) {
        int ppow = pow(10, pw-1);
        cout << ppow << endl;
        int tg = (n/ppow)%10;
        cout << tg << endl;
        pw++;
    }
}

