#include <iostream>
#include <cmath>
using namespace std;

int n;

double log2(long long int x) {
    return log(x)/log(2);
}

void matrix_product(int** m1, int** m2, int** &out) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int cal=0;
            for(int k=0;k<n;k++) {
                cal += (m1[i][k]*m2[k][j])%1000;
                cal %= 1000;
            }
            out[i][j] = cal;
        }
    }
    return;
}

void print(int** m) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int main() {
    long long int b;
    int **matrix, **ans_matrix;
    int ***mul;
    cin >> n >> b;
    matrix = new int*[n];
    ans_matrix = new int*[n];
    for(int i=0;i<n;i++) {
        matrix[i] = new int[n];
        ans_matrix[i] = new int[n];
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }
    int how = log2(b);
    mul = new int**[how+1];
    for(int i=0;i<=how;i++) {
        mul[i] = new int*[n];
        for(int j=0;j<n;j++) {
            mul[i][j] = new int[n];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            mul[0][i][j] = matrix[i][j]%1000;
        }
    }
    //cout << "mul[0]\n";
    //print(mul[0]);
    for(int i=1;i<=how;i++) {
        matrix_product(mul[i-1], mul[i-1], mul[i]);
        //cout << "mul[" << i << "]\n";
        //print(mul[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans_matrix[i][j] = mul[how][i][j];
        }
    }
    //cout << "ans\n";
    //print(ans_matrix);
    long long int remain = b-(long long int)pow(2, how);
    while(remain!=0) {
        how = log2(remain);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                matrix[i][j] = ans_matrix[i][j];
            }
        }
        matrix_product(matrix, mul[how], ans_matrix);
        //cout << "ans\n";
        //print(ans_matrix);
        remain -= (long long int)pow(2, how);
    }
    //cout << "ans\n";
    print(ans_matrix);
    return 0;
}