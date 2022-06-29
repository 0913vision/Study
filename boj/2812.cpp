#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int n, k;
    deque<char> q;
    string input;
    cin >> n >> k >> input;
    for(int i=0;i<n;i++) {
        while(k>0 && !q.empty() && q.back() < input[i]) {
            q.pop_back();
            k--;
        }
        q.push_back(input[i]);
    }
    for(int i=0;i<q.size()-k;i++) {
        cout << q[i];
    }

    return 0;
}