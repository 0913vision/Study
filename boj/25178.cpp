#include <iostream>
#include <string>
using namespace std;

bool ismo(char a) {
    if(a=='a' || a=='i' || a=='e' || a=='o' || a=='u') return true;
    return false;
}

int main() {
    int n, flag;
    string s1, s2;
    int alpha[26] = {0, };
    cin >> n >> s1 >> s2;

    flag = 0;
    if(s1[0]!=s2[0] || s1[n-1]!=s2[n-1]) {
        cout << "NO";
        return 0;
    }

    for(int i=0;i<n;i++) {
        alpha[s1[i]-'a']++;
        alpha[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(alpha[i]%2 != 0) {
            cout << "NO";
            return 0;
        }
    }

    int i=0,j=0;
    
    while(i!=n && j!=n) {
        while(i!=n && ismo(s1[i])) i++;
        while(j!=n && ismo(s2[j])) j++;
        if(i==n || j==n) break;
        if(s1[i] != s2[j]) {
            cout << "NO";
            return 0;
        }
        else {
            i++;
            j++;
        }
    }

    cout << "YES";
    return 0;
}