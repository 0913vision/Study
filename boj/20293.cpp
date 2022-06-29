#include <iostream>
#include <algorithm>
#include <vector>
#define pp(x,y) make_pair(x, y)
#define INF 987654321
using namespace std;

/*void print_arr(int **arr, int r, int c) {
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}*/

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    int **dp = new int*[r+2]; //dp[i][j] (1,1)부터 (i,j)까지 갈 때의 순비용 (비용 - 충전)
    int **oil = new int*[r+2];
    for(int i=0;i<=r+1;i++) {
        oil[i] = new int[c+2];
        dp[i] = new int[c+2];
        for(int j=0;j<=c+1;j++) {
            oil[i][j] = 0;
            dp[i][j] = (-1)*INF;
        }
    } // initailization
    for(int i=0;i<n;i++) {
        int x, y, b;
        cin >> x >> y >> b;
        oil[x][y] = b;
    }
    dp[r][c] = 0;
    for(int i=r;i>0;i--) {
        for(int j=c;j>0;j--) {
            if(i==r && j==c) continue;
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + oil[i][j] - 1;
            if(dp[i][j]>0) dp[i][j] = 0;
        }
    }
    
    //print_arr(dp, r, c); cout << "\n";
    //print_arr(oil, r, c);

    cout << (-1)*dp[1][1] << "\n";
    
    return 0;
}