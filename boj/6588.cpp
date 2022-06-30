#include <iostream>
#include <vector>
using namespace std;

int set[1010101] = {0,}; // 0 is prime, 1 is not prime.
vector<int> prime;
void makeSet() {
    for(int i=2;i<=1000000;i++) {
        if(set[i]==0) {
            prime.push_back(i);
            for(int j=i*2;j<=1000000;j+=i) {
                set[j] = 1;
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    makeSet();

    int a, b, n;

    while(true) {
        cin >> n;
        if(n==0) break;
        int i=1, a=2, b=n-a;
        while(set[b]!=0) {
            a = prime[i++];
            b = n-a;
        }
        cout << n << " = " << a << " + " << b << "\n";
    }
    return 0;
}