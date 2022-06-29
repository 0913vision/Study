#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int *bits, *gap, n, m, bit_len, gap_max = -1;
vector<int> hack;

void howbits() {
    int tmp=n;
    bit_len=0;
    while(tmp>0) {
        tmp /= 2;
        bit_len++;
    }
    bits = new int[bit_len];
    gap = new int[bit_len];
    return;
}

void bit_check(int s) {
    int b = 1<<s;
    int one, zero;
    one = zero = 0;
    for(int i=0;i<m;i++) {
        int target = hack[i];
        int mask = b&target;
        if(mask == 0) {
            zero++;
        }
        else {
            one++;
        }
    }
    if(zero <= one) bits[s] = 0;
    else bits[s] = 1;

    gap[s] = zero-one;
    if(gap[s]<0) gap[s] *= -1;
    if(gap_max < gap[s]) gap_max = gap[s];
    return;
}

int safe(int p) {
    int target, tmp, min, sum;
    min = 987654321;
    for(int i=0;i<m;i++) {
        target = hack[i]^p;
        sum = 0;
        while(target!=0) {
            tmp = target&1;
            sum += tmp;
            target = target>>1;
        }
        if(min > sum) min = sum;
    }
    return min;
}

int main() {
    cin >> n >> m;
    howbits();
    for(int i=0;i<m;i++) {
        int x; cin >> x;
        hack.push_back(x);
    }
    for(int i=0;i<bit_len;i++) {
        bit_check(i);
    }
    int password=0;
    for(int i=bit_len-1;i>=0;i--) {
        int tmp;
        if(bits[i] == 1) tmp = 1;
        else tmp = 0;
        password += tmp << i;
    }
    int how_gap = 1;
    while(password > n) {
        for(int i=bit_len-1;i>=0;i--) {
            int miuns = 1<<i;
            if(password > n && bits[i]==1 && gap[i]==how_gap) {
                password -= miuns;
            }
        }
        how_gap++;
    }
//  cout << password << " ";
    cout << safe(password);

    return 0;
}