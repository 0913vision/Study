#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t, n, two, res1, res2, tmp, odd, even;
    int arr_odd[16], arr_even[16];
    cin >> t;
    while(t--) {
        cin >> n;
        two=odd=even=0;
        for(int i=0;i<n;i++) {
            cin >> tmp;
            if(tmp%2==1) {
                arr_odd[odd++] = tmp;
            }
            else {
                arr_even[even++] = tmp;
                if(tmp%8==0) two+=3;
                else if(tmp%4==0) two+=2;
                else two+=1;
            }
        }
        sort(arr_odd, arr_odd+odd);
        sort(arr_even, arr_even+even);

        res1 = res2 = 0;

        if(odd>0) {
            res1 = arr_odd[odd-1] * (int)pow(2, two);
            for(int i=0;i<even;i++) {
                res1 += arr_even[i]/(int)pow(2, (int)log2(arr_even[i]));
            }
            for(int i=0;i<odd-1;i++) {
                res1 += arr_odd[i];
            }
        }
        
        if(even>0) {
            res2 = arr_even[even-1] * (int)pow(2, two-(int)log2(arr_even[even-1]));
            cout << res2 << "\n";
            for(int i=0;i<even-1;i++) {
                res2 += arr_even[i]/(int)pow(2, (int)log2(arr_even[i]));
            }
            for(int i=0;i<odd;i++) {
                res2 += arr_odd[i];
            }
        }

        cout << max(res1, res2) << "\n";
    }
    return 0;
}