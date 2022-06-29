#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int *arr = new int[n];
        int flag = 1;
        for(int i=0;i<n;i++) {
            int x; cin>>arr[i];
        }
        for(int i=0;i<n;i++) {
            if(flag==1) {
                cout << arr[i/2] << " ";
            }
            else {
                cout << arr[n-(i/2)-1] << " ";
            }
            flag *= -1;
        }
        cout << "\n";
        delete [] arr;
    }
    return 0;
}