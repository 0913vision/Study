#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int ****car;
int **dp;
vector<pair<int, int>> event;

int dist(int a1, int b1, int a2, int b2) {
    return abs(a1-a2) + abs(b1-b2);
}

int move(int eventNum, int dispatch, int target) {
    return dist(event[eventNum].first, event[eventNum].second, car[eventNum-1][dispatch][target][0], car[eventNum-1][dispatch][target][1]);
}

int main() {
    int n, w, t1, t2, total_length, next_value;
    cin >> n >> w;
    vector<int> backtrac;

    dp = new int*[w];
    for(int i=0;i<w;i++) {
        dp[i] = new int[2];
    }

    car = new int***[w];
    for(int i=0;i<w;i++) {
        car[i] = new int**[2];
        for(int j=0;j<2;j++) {
            car[i][j] = new int*[2];
            for(int k=0;k<2;k++) {
                car[i][j][k] = new int[2];
                car[i][j][k][0] = 0;
                car[i][j][k][1] = 0;
            }
        }
    }

    for(int i=0;i<w;i++) {
        cin >> t1 >> t2;
        event.push_back(make_pair(t1, t2));
    }

    dp[0][0] = dist(event[0].first, event[0].second, 1, 1);
    car[0][0][0][0] = event[0].first;
    car[0][0][0][1] = event[0].second;
    car[0][0][1][0] = n;
    car[0][0][1][1] = n;
    dp[0][1] = dist(event[0].first, event[0].second, n, n);
    car[0][1][0][0] = 1;
    car[0][1][0][1] = 1;
    car[0][1][1][0] = event[0].first;
    car[0][1][1][1] = event[0].second;
    cout << "dp[" << 0 << "][" << 0 << "] = " << dp[0][0] << "\n";
    cout << "dp[" << 0 << "][" << 1 << "] = " << dp[0][1] << "\n";

    for(int i=1;i<w;i++) {
        for(int j=0;j<2;j++) {
            cout << i+1 << "th event, " << j+1 << "th police car solved.\n";
            t1 = dp[i-1][0]+move(i, 0, j);
            t2 = dp[i-1][1]+move(i, 1, j);
            dp[i][j] = min(dp[i-1][0]+move(i, 0, j), dp[i-1][1]+move(i, 1, j));
            if(t1<=t2) {
                dp[i][j] = t1;
                car[i][j][(j-1)*(-1)][0] = car[i-1][0][(j-1)*(-1)][0];
                car[i][j][(j-1)*(-1)][1] = car[i-1][0][(j-1)*(-1)][1];
                cout << "before dispatch is 1st car.\ndp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
            }
            else {
                dp[i][j] = t2;
                car[i][j][(j-1)*(-1)][0] = car[i-1][1][(j-1)*(-1)][0];
                car[i][j][(j-1)*(-1)][1] = car[i-1][1][(j-1)*(-1)][1];
                cout << "before dispatch is 2nd car.\ndp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
            }/*
            else {

            }*/
            car[i][j][j][0] = event[i].first;
            car[i][j][j][1] = event[i].second;
            cout << "\n";
        }
        cout << "\n";
    }
    total_length = min(dp[w-1][0], dp[w-1][1]);
    cout << total_length << "\n";

    // backtrac

    for(int i=w-1;i>0;i--) {
        if(total_length == dp[i][0])
            next_value = 0;
        else
            next_value = 1;
        backtrac.push_back(next_value);
        t1 = move(i,0,next_value);
        t2 = move(i,1,next_value);

        if(total_length == dp[i-1][0] + t1)
            total_length -= t1;
        else
            total_length -= t2;
    }

    if(total_length == dp[0][0])
        backtrac.push_back(0);
    else
        backtrac.push_back(1);

    for(vector<int>::reverse_iterator it=backtrac.rbegin();it!=backtrac.rend();it++) {
        cout << (*it)+1 << "\n";
    }

    return 0;
}