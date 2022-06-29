#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <memory.h>
#define INT_MAX 2147483647
using namespace std;


vector<pair<int, int>> p1, p2;
vector<int> trac;
int dp[1010][1010], n, w;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int makeTable(int x, int y) {
    // x는 1번차가 이동한 횟수, y는 2번차가 이동한 횟수
    int nextEventNumber, d1, d2, t1, t2;
    if(x==w || y==w) return 0; // 횟수가 w를 넘어가면 0반환 (이동안함)
    if(dp[x][y] >= 0) return dp[x][y]; // 이미 값이 존재하면 그 값을 반환

    nextEventNumber = max(x, y)+1; // 다음 사건
    d1 = dist(p1[nextEventNumber], p1[x]); // 다음사건의 위치와 현재 1번 차의 거리
    d2 = dist(p2[nextEventNumber], p2[y]); // 다음사건의 위치와 현재 2번차의 거리

    t1 = d1 + makeTable(nextEventNumber, y); // 1번차가 이동했을 경우 그 다음번 거리
    t2 = d2 + makeTable(x, nextEventNumber); // 2번차가 이동했을 경우 그 다음번 거리

    // 마지막까지 모두 카운트하게 된다.

    dp[x][y] = min(t1, t2); // 이게 최소값임. 배열 갱신
    return dp[x][y]; // 반환
}

void calculation(int x, int y) { // 추적
    int nextEventNumber, d1, d2, t1, t2;
    if(x==w || y==w) return;

    nextEventNumber = max(x, y)+1;
    d1 = dist(p1[nextEventNumber], p1[x]);
    d2 = dist(p2[nextEventNumber], p2[y]);

    t1 = d1 + makeTable(nextEventNumber, y);
    t2 = d2 + makeTable(x, nextEventNumber);

    // 배열 만들때와 같음. 이때 모든 dp가 만들어져 있으므로 바로 반환된다.

    if(t1 < t2) { // 이동거리 짧은 걸 골라서
        trac.push_back(1); // 해당 차 출력하고
        calculation(nextEventNumber, y); // 다음사건으로 이동
    }
    else {
        trac.push_back(2);
        calculation(x, nextEventNumber);
    }
    // 모든 사건 다 다루게 된다
    return; // 끝
}

int main() {
    int a, b;
    cin >> n >> w;

    p1.push_back(make_pair(1,1));
    p2.push_back(make_pair(n,n));

    for(int i=0;i<w;i++) {
        cin >> a >> b;
        p1.push_back(make_pair(a, b));
        p2.push_back(make_pair(a, b));
    }
    memset(dp, -1, sizeof(dp));

    cout << makeTable(0, 0) << "\n"; // 처음부터 끝까지 dp계산
    calculation(0, 0); // 출력
    for(vector<int>::iterator it=trac.begin();it!=trac.end();it++) {
        cout << (*it) << "\n";
    }
    return 0;
}