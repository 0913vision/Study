#include <iostream>
#include <climits>
using namespace std;

int useIndex(int* seq, int prod, int start, int end) {
    int ret = -1;
    for(int i=start;i<end;i++) {
        if(seq[i] == prod) {
            ret = i;
            break;
        }
    }
    return ret;
}

int main() {
    int n, k, min_val, min_idx; cin >> n >> k;
    int *sw = new int[k+1];
    int *seq = new int[k];
    for(int i=0;i<=k;i++) {
        sw[i] = 0;
    }
    for(int i=0;i<k;i++) {
        int x; cin>>seq[i];
    }
    int cnt = 0;
    int using_hole = 0;
    for(int i=0;i<k;i++) {
        int target = seq[i];
        if(sw[target]==0 && using_hole < n) {
            sw[target] = 1;
            using_hole++;
        }
        else if(sw[target] != 1) { // 새로 제품을 꽂아야하는 상황
            int remove = -1;
            for(int j=1;j<=k;j++) { // 존재성확인
                if(sw[j]==1 && useIndex(seq, j, i+1, k)==-1) { // j번째 제품은 더 이상 쓸 곳이 없다.
                    sw[j] = 0; // 스위치 off
                    sw[target] = 1; // 해당 제품 on
                    cnt++; // 뽑은 횟수 1추가
                    break;
                }
            } 
            if(sw[target]==0) { // 못꽂은경우 <=> 위에서 고른 제품이 없을 경우
                int lastest = -1;
                for(int j=1;j<=k;j++) {
                    if(sw[j] == 1 && j!=target) {
                        int u = useIndex(seq, j, i+1, k);
                        if(u > lastest) { // 가장 늦게 사용할 제품을 선택한다.
                            remove = j;
                            lastest = u;
                        }
                    }
                }
                sw[remove] = 0; // 가장늦게쓰는것을 끄고
                sw[target] = 1; // 스위치 on
                cnt++; // 뽑은 횟수 1추가
            }
        }
    }
    cout << cnt;
    return 0;
}