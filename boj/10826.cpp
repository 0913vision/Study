#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bigAdd(string A, string B) {
    string ret(max(A.size(), B.size()), '0');
    int carryNum = 0, sum;

    for(int i=0;i<ret.size();i++) {
        sum = carryNum;
        carryNum = 0;
        if(i < A.size()) {
            sum += A[A.size()-i-1] - '0';
        }
        if(i < B.size()) {
            sum += B[B.size()-i-1] - '0';
        }
        if(sum>9) {
            carryNum = 1;
            sum -= 10;
        }
        ret[ret.size()-i-1] = sum + '0';
    }

    if(carryNum==1)
        ret.insert(ret.begin(), '1');

    return ret;
}

int main() {
    int n;
    string *fibo, a;

    cin >> n;
    fibo = new string[n+10];
    
    fibo[0] = "0";
    fibo[1] = "1";

    for(int i=2;i<=n;i++) {
        fibo[i] = bigAdd(fibo[i-1], fibo[i-2]);
    }

    cout << fibo[n];

    return 0;
}