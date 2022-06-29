#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void solve(int n, int init, int dest, int tmp) {
    if(n==1) {
        cout << init << " " << dest << "\n";
        return;
    }
    solve(n-1, init, tmp, dest); // ���� ģ������ ��� tmp���� ������
    cout << init << " " << dest << "\n";
    solve(n-1, tmp, dest, init); // �Ʊ� tmp�� ���� ģ������ �ٽ� dest���� ������
    return;
}

int main() {
    int n;
    cin >> n;
    // ����ߴ��� ���
    string count = to_string(pow(2,n));
    count[count.find('.')-1] -= 1;
    cout << count.substr(0,count.find('.')) << "\n";
    if(n<=20) solve(n, 1, 3, 2);
    return 0;
}
/*

    */