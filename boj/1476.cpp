#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int te, ts, tm;
    int e, s, m;
    cin >> te >> ts >> tm;

    int year = 1;
    e = 0, s = 0, m = 0;

    while(!(e+1==te && s+1==ts && m+1==tm)) {
        year++;
        e = (e+1)%15;
        s = (s+1)%28;
        m = (m+1)%19;
    }
    cout << year;
    return 0;
}