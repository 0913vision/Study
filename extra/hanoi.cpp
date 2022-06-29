#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void solve(int n, int init, int dest, int tmp) {
    if(n==1) {
        cout << init << " " << dest << "\n";
        return;
    }
    solve(n-1, init, tmp, dest); // 위에 친구들을 모두 tmp으로 보낸다
    cout << init << " " << dest << "\n";
    solve(n-1, tmp, dest, init); // 아까 tmp로 보낸 친구들을 다시 dest위로 보낸다
    return;
}

int main() {
    int n;
    cin >> n;
    // 몇번했는지 출력
    string count = to_string(pow(2,n));
    count[count.find('.')-1] -= 1;
    cout << count.substr(0,count.find('.')) << "\n";
    if(n<=20) solve(n, 1, 3, 2);
    return 0;
}
/*

    */