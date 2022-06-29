#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin>>n>>k;
    int *arr = new int [n+1];
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    cout << arr[k];
    return 0;
}