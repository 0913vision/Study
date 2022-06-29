//merry christmas tree
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define divConst 1000000007
using namespace std;

vector<pair<int, int>> *vertex;
long long int sum = 0;

long long int dfs(int target, int root) {
    long long int childSum=1, targetChildSum;
    // childSum의 초기값이 1인 이유 = 상위 노드에서 자신이 가지고 있는 트리의 가중치에 간선의 가중치를 곱하기 때문에
    //cout << target << ", " << root << "\n";
    for(auto iter : vertex[target]) {
        if(iter.first != root) { // subtree만 보기
            targetChildSum = dfs(iter.first, target) * iter.second % divConst; // subtree의 가중치
            //cout << "targetChildSum = " << targetChildSum << " ";
            sum += childSum * targetChildSum % divConst; // 현재까지 구한 subtree의 가중치 * 지금 구한 subtree의 가중치 = 서로 다른 subtree에서 한 점씩 뽑아서 연결한 것
            //cout << "sum = " << sum << "\n";
            sum %= divConst;
            childSum += targetChildSum; // 현재까지 구한 subtree의 가중치의 합 (각 subtree의 가중치는 independent하다.)
            childSum %= divConst;
        }
    }
    //cout << "childSum = " << childSum << "\n";
    return childSum;
}

int main() {
    int n, a, b, w;
    cin >> n;

    vertex = new vector<pair<int, int>>[n+1];

    for(int i=0;i<n-1;i++) {
        cin >> a >> b >> w;
        vertex[a].push_back(make_pair(b, w));
        vertex[b].push_back(make_pair(a, w));
    }

    dfs(1, 1);
    cout << sum;

    return 0;
}