#include <iostream>
using namespace std;

char arr[50][50] = {0,};
int n;

int analyze() {
    int len, maxlen=-1;
    for(int i=0;i<n;i++) {
        len = 1;
        for(int j=1;j<n;j++) {
            if(arr[i][j] == arr[i][j-1]) len++;
            else {
                maxlen = max(maxlen, len);
                len=1;
            }
        }
        maxlen = max(maxlen, len);
        len = 1;
        for(int j=1;j<n;j++) {
            if(arr[j][i] == arr[j-1][i]) len++;
            else {
                maxlen = max(maxlen, len);
                len=1;
            }
        }
        maxlen = max(maxlen, len);
    }
    return maxlen;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int maxv = -1;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            if(arr[i][j] != arr[i][j+1]) {
                swap(arr[i][j], arr[i][j+1]);
                maxv = max(maxv, analyze());
                swap(arr[i][j], arr[i][j+1]);
            }
        }
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j] != arr[i+1][j]) {
                swap(arr[i][j], arr[i+1][j]);
                maxv = max(maxv, analyze());
                swap(arr[i][j], arr[i+1][j]);
            }
        }
    }
    cout << maxv;

    return 0;
}