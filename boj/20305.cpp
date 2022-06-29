#include <iostream>
#include <map>
#define mod 1000000007
#define pp(x,y) make_pair(x, y)
using namespace std;

int *seq, *fibo, n, q;
map<int, int> *query;

void cal_fibo() {
    for(int i=2;i<=n;i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2])%mod;
    }
    return;
}

int main() {
    map<int,int>::iterator it;
    cin >> n >> q;
    fibo = new int[n+1]; fibo[0]=0 ; fibo[1]=1;
    cal_fibo();
    query = new map<int, int>[n+1];
    seq = new int[n+1];
    for(int i=0;i<=n;i++) {
        seq[i] = 0;
    }
    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        for(int j=l;j<=r;j++) {
            it = query[j-l+1].find(j);
            if(it!=query[j-l+1].end()) {
                (*it).second += 1;
            }
            else {
                query[j-l+1].insert(pp(j, 1));
            }
        }
    }
    int a, cost;
    for(int i=1;i<=n;i++) {
        for(it=query[i].begin();it!=query[i].end();it++) {
            a=(*it).first;
            cost=(*it).second;
            seq[a] += (fibo[i]*cost)%mod;
            seq[a] %= mod;
        }
    }
    for(int i=1;i<=n;i++) {
        cout << seq[i] << " ";
    }

    return 0;
}