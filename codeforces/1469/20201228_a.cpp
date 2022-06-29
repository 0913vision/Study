#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, open, close, lq, rq, iq, no;
    string input;
    cin >> t;
    while(t--) {
        cin >> input;
        open = 0; lq=0; rq=0; iq=0; no=0; close=0;
        if(input.size()%2==1)
            no=1;
        for(int i=0;i<input.size();i++) {
            if(input[i] == '(') {
                lq++;
                open=1;
                close=0;
            }
            if(input[i] == '?') {
                if(open==0 && close==0) {
                    lq++;
                }                
                else if(close==1) {
                    rq++;
                }
                else if(open==1 && close==0) {
                    iq++;
                }
            }
            if(input[i] == ')') {
                close = 1;
                if(open==0) {
                    if(lq>0) {
                        lq--;
                    }
                    else {
                        no=1;
                        break;
                    }
                }
                else if(open==1) {
                    rq++;
                }
            }
        }
        if(open==1 && close==0 && iq==0) {
            no=1;
        }
        else if(lq<rq) {
            rq -= lq;
            lq=0;
            if((rq+iq)%2==1)
                no=1;
        }
        else if(lq>rq) {
            lq -= rq;
            rq=0;
            if((lq+iq)%2==1)
                no=1;
        }
        else if(lq==rq) {
            if(iq%2==1) {
                no=1;
            }        
        }

        if(no==1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}