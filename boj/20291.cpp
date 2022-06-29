#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define pp(x,y) make_pair(x, y)
using namespace std;

int main() {
    int n;
    map<string, int> m;
    map<string, int>::iterator it;
    cin >> n;
    for(int i=0;i<n;i++) {
        string tmp, type;
        cin >> tmp;
        type = tmp.substr(tmp.find('.', 0)+1);
        it = m.find(type);
        if(it == m.end()) {
            m.insert(pp(type, 1));
        }
        else {
            (*it).second += 1; 
        }
    }
    for(it=m.begin();it!=m.end();it++) {
       cout << (*it).first << " " << (*it).second << "\n";
    }
    return 0;
}