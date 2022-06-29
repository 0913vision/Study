#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int x, n, maxTime;
    cin >> n;
    ii *arr = new ii[n];
    int *output;
    int time[101010] = {0,};

    for(int i=0;i<n;i++) {
        cin >> x;
        arr[i] = make_pair(x, i);
        time[x]++;
    }
    
    maxTime = 0;
    for(int i=1;i<=100000;i++) {
        maxTime = max(maxTime, time[i]);
    }

    if(maxTime*2>n) {
        cout << "-1";
        delete[] arr;
        return 0;
    }

    output = new int[n];
    sort(arr, arr+n);

    for(int i=0;i<n;i++) {
        x = (i+maxTime)%n;
        output[arr[i].second] = arr[x].first;
    }

    for(int i=0;i<n;i++) {
        cout << output[i] << " ";
    }

    delete[] arr, output;
    return 0;
}