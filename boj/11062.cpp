//interesting card game!
#include <iostream>
#include <algorithm>
#include <memory.h>
#define LEFT 0
#define RIGHT 1
using namespace std;

int *card;

int table[1010][1010];
int ctable[1010][1010];
int n;

int dp(int L, int R) {
    int cl, cr, el, er, ecl, ecr;
    if(table[L][R] > -1) return table[L][R];

    if(L>R)
        table[L][R] = 0;
    else if(L==R) {
        table[L][L] = card[L];
        ctable[L][L] = LEFT;
    }
    else if(R-L==1) {
        if(card[L]<card[R]) {
            ctable[L][R] = RIGHT;
            table[L][R] = card[R];
        }
        else {
            ctable[L][R] = LEFT;
            table[L][R] = card[L];
        }
    }

    else {
        cl = dp(L+1, R);
        cr = dp(L, R-1); // cr = 명우가 L, R-1 카드에서 최선으로 보는 이득
        if(cl<cr) { // 오른쪽 고르면 명우가 이득보는게 커짐
            // 그럼 근우는 왼쪽을 골라야하고
            if(ctable[L+1][R] == LEFT) { // 근우가 왼쪽을 골랐을 때 명우가 고른 카드가 왼쪽이라면
                table[L][R] = card[L] + dp(L+2,R); // 왼쪽카드 + 나머지에서 최선
            }
            else { // 근우가 왼쪽을 골랐을 때 명우가 고른 카드가 오른쪽이라면
                table[L][R] = card[L] + dp(L+1,R-1); // 왼쪽카드 + 나머지에서 최선
            }
            ctable[L][R] = LEFT; // 근우 왼쪽고름
        }
        else { // 왼쪽을 고르면 명우가 이득보는게 커짐
            // 그럼 근우는 오른쪽을 골라야하고
            if(ctable[L][R-1] == LEFT) { //근우가 오른쪽을 골랐을 때 명우가 고른 카드가 왼쪽이라면
                table[L][R] = card[R] + dp(L+1, R-1); // 오른쪽카드 + 나머지에서 최선
            }
            else { // 근우가 오른쪽을 골랐을 때 명우가 고른 카드가 오른쪽이라면
                table[L][R] = card[R] + dp(L, R-2); // 오른쪽카드 + 나머지에서 최선
            }
            ctable[L][R] = RIGHT; // 근우 오른쪽 고름
        }
    }
    return table[L][R];
}

int main() {
    int t, **gdp, **mdp, gs;
    cin >> t;
    while(t--) {
        cin >> n;
        card = new int[n];
        for(int i=0;i<n;i++) {
            cin >> card[i];
        }
        memset(table, -1, sizeof(table));
        cout << dp(0,n-1) << "\n";
        delete [] card;
    }
    return 0;
}