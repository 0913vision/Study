#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *a, *b;
    a = new int[n];
    b = new int[m];

    int add = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
        if(i>=n && b[i]>add) // 없어진 장소이므로 무조건 증가 
            add = b[i];
        else if(b[i]>a[i] && b[i]-a[i]>add)
            add = b[i]-a[i];
    }
    cout << add;
    return 0;
}