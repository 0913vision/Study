#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;

typedef tuple<int, int, int> tt;
typedef vector<tt>::iterator tti;

bool comp(tt a, tt b) {
    return (get<0>(a) < get<0>(b)) ? true : false;
}

int main() {
    int n;
    cin >> n;
    vector<tt> line;
    FOR(i, n) {
        int s, e, c;
        cin >> s >> e >> c;
        line.push_back(make_tuple(s,e,c));
    }
    sort(line.begin(), line.end(), comp);

    vector<tt> ans;

    int start=-1, end, cost;

    for(tti it=line.begin();it!=line.end();it++) {
        int s, e, c;
        if(start==-1) {
            tie(start, end, cost) = *it;
        }
        else {
            tie(s,e,c) = *it;
            if(s<=end) {
                if(e>end) {
                    end = e;
                }
                if(c<cost) {
                    cost = c;
                }
            }
            else {
                ans.push_back(make_tuple(start, end, cost));
                start = s; end = e; cost = c;
            }
        }
    }
    ans.push_back(make_tuple(start, end, cost));

    sort(ans.begin(), ans.end(), comp);

    cout << ans.size() << "\n";
    for(tti it=ans.begin();it!=ans.end();it++) {
        int s,e,c;
        tie(s,e,c) = *it;
        cout << s << " " << e << " " << c << "\n";
    }
    return 0;
}