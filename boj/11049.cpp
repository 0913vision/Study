#include <iostream>
#include <vector>
#define INTMAX 2147483647

using namespace std;

int main() {
	int n, r, c, min, tmp;
	
	cin >> n;
	vector<pair<int, int>> v;
	int dp[n][n];
	
	for(int i=0;i<n;i++) {
		cin >> r >> c;
		v.push_back(make_pair(r, c));
	}
	
	for(int i=0;i<n;i++) {
		dp[i][i] = 0;
	}
	for(int i=0;i<n-1;i++) {
		dp[i][i+1] = v[i].first * v[i].second * v[i+1].second;
		//cout << dp[i][i+1] << endl;
	}
	
	for(int l=3;l<=n;l++) { // 길이 
		for(int	i=0;i<n-l+1;i++) { // 시작인덱스 (끝 인덱스는 길이로 자동 결정) 
			min = INTMAX;
			for(int j=i;j<i+l-1;j++) { // dp계산 i번째부터 i+l-1까지 
				//cout << "i=" << i << ", j=" << j << endl;
				//cout << dp[i][j] << ", " << dp[j+1][i+l-1] << ", " << v[i].first * v[j].second * v[i+l-1].second << endl;
				tmp = dp[i][j] + dp[j+1][i+l-1] + v[i].first * v[j].second * v[i+l-1].second;
				//cout << tmp << endl;
				if(min > tmp)
					min = tmp;
			}
			dp[i][i+l-1] = min;
		}
	}
	
	cout << dp[0][n-1];

	return 0;
}