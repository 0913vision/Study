#include <iostream>
using namespace std;

typedef struct _node {
    int key;
    _node* prev;
    _node* next;
} NODE;

bool allSame(NODE* arr) {
    int s = arr->key;
    arr = arr->next;
    while(arr!=0) {
        if(arr->key != s)
            return false;
        arr = arr->next;
    }
    return true;
}

int main() {
    NODE* arr=0, *cur;
    int t; cin >> t;
    while(t--) {
        arr = 0;
        int n; cin >> n;
        for(int i=0;i<n;i++) {
            int x; cin >> x;
            if(arr==0) {
                arr = new NODE[1];
                arr->prev = 0;
                arr->next = 0;
                arr->key = x;
                cur = arr;
            }
            else {
                cur->next = new NODE[1];
                cur->next->prev = cur;
                cur->next->next = 0;
                cur->next->key = x;
                cur = cur->next;
            }
        }
        int cnt = 0;
        while(!allSame(arr)) {
            cnt++;
            int m=3001; NODE* target=0; NODE* tmp;
            cur = arr;
            while(cur->next!=0) {
                if(m > cur->key + cur->next->key) {
                    m=cur->key + cur->next->key;
                    target = cur;
                }
                cur = cur->next;
            }
            target->key = m;
            tmp = target->next;
            target->next = tmp->next;
            if(target->next != 0)
                target->next->prev = target;
            delete [] tmp;
        }
        cout << cnt << "\n";
        while(arr!=0) {
            NODE* tmp = arr->next;
            delete [] arr;
            arr = tmp;
        }
    }
    return 0;
}