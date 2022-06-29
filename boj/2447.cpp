#include <iostream>
#include <cmath>
using namespace std;

int n;
char **result;

void solve(int size, int I, int J, char target) {
    if(size==3) {
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i*j==1) {
                    result[i+I][j+J] = ' ';
                }
                else {
                    result[i+I][j+J] = target;
                }
            }
        }
        return;
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i*j==1)
                solve(size/3, I+(i*size/3), J+(j*size/3), ' ');
            else {
                solve(size/3, I+(i*size/3), J+(j*size/3), target);
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    result = new char*[n];
    for(int i=0;i<n;i++) {
        result[i] = new char[n];
    }
    solve(n, 0, 0, '*');
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}