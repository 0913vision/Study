#include <iostream>
#include <algorithm>
#include <vector>
#define pp(x,y) make_pair(x, y)
#define for(i,start,n) for(int i=start;i<n;i++)
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
    if(x.second == y.second) {
        return x.first < y.first;
    }
    return x.second < y.second;
}

int main() {
    int t;
    vector<pair<int,int>> student;
    int *book;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        book = new int[n+1];
        for(i,1,n+1) {
            book[i] = 0;
        }
        for(i, 0, m) {
            int a, b;
            cin >> a >> b;
            student.push_back(pp(a,b));
        }
        sort(student.begin(), student.end(), cmp);
        int cnt = 0;
        for(i, 0, m) {
            for(j, student[i].first, student[i].second+1) {
                if(book[j] == 0) {
                    book[j] = 1;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
        delete [] book;
        vector<pair<int, int>>().swap(student);
    }
}