#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull sigma[1010101] = {0,};

void dynamic(int n) {
    int j=1, k=1;
    ull sum = 0;
    int flag = 1;
    int time;
    sigma[1] = 1;
    sigma[2] = 3;
    for(int i=3;i<=n;i++) {
        j=1, k=1, sum=0, flag = 0;
        do {
            if(flag>1) {
                time = -1;
            }
            else {
                time = 1;
            }
            if(k==i) {
                sum += i*time;
            }
            else {
                sum += time*sigma[i-k];
            }
            if(flag%2 == 0) {
                j *= -1;
            }
            else {
                j = j*(-1)+1;
            }
            flag = (flag+1)%4;
            k = j*(3*j-1)/2;
        } while(k<=i);
        sigma[i] = sum;
    }
    return;
}


int main() {
    int n;
    cin >> n;

    dynamic(n);

    // for(int i=1;i<=n;i++) {
    //     cout << "sigma[" << i << "] = " << sigma[i] << endl;
    // }

    ull sum = 0;
    for(int i=1;i<=n;i++) {
        sum += sigma[i];
    }
    cout << sum;

    return 0;
}

// 실패이유 : divisor function을 삼각수로 구하면 시간초과가 난다.
// 규칙으로 접근하는 방식이 필요함.