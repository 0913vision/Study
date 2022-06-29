#include <iostream>
using namespace std;

int n;
int **arr;
int neg, zero, pos;

void input() {
    neg = zero = pos = 0;
    cin >> n;
    arr = new int*[n];
    for(int i=0;i<n;i++) {
        arr[i] = new int[n];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    return;
}

void cal(int I, int J) {
    int &x = arr[I][J];
    if(x==-1) neg++;
    else if(x==0) zero++;
    else pos++;
    return;
}

bool isSame(int size, int I, int J) {
    int ans = arr[I][J];
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(ans != arr[I+i][J+j])
                return false;
        }
    }
    return true;
}

void solve(int size, int I, int J) {
    if(isSame(size, I, J)) {
        cal(I, J);
        return;
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            solve(size/3, I+(size/3*i), J+(size/3*j));
        }
    }
    return;
}

int main() {
    input();
    solve(n, 0, 0);
    cout << neg << "\n" << zero << "\n" << pos;
    return 0;
}