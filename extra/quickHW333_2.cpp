#include <iostream>
using namespace std;
#define For(i,n) for(int (i)=0;(i)<(n);(i)++)

// global variables
int n, m;
int *card, *question;
int *sorted;

// function prototypes
void input();
void solve();
void output();

void merge_sort(int left, int right);
void merge(int left, int mid, int right);
int search(int key);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    output();

    return 0;
}

void input() {
    cin >> n;
    card = new int[n];
    For(i, n) {
        cin >> card[i];
    }

    cin >> m;
    question = new int[m];
    For(i, m) {
        cin >> question[i];
    }
}

void solve() {
    sorted = new int[n];
    merge_sort(0, n-1);
    //delete [] sorted;
}

void output() {
    For(i, m) {
        cout << search(question[i]) << " ";
    }
}

void merge_sort(int left, int right) {
    int mid;
    if(left<right) {
        mid = (left+right)/2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}

void merge(int left, int mid, int right) {
    int i,j,k;
    i = k = left;
    j = mid+1;

    while(i<=mid && j<=right) {
        if(card[i]<=card[j])
            sorted[k++] = card[i++];
        else
            sorted[k++] = card[j++];
    }
    if(i>mid) {
        for(int x=j;x<=right;x++) {
            sorted[k++] = card[x];
        }
    }
    else {
        for(int x=i;x<=mid;x++) {
            sorted[k++] = card[x];
        } 
    }
    for(int x=left;x<=right;x++) {
        card[x] = sorted[x];
    }
}

int search(int key) {
    int mid;
    int left = 0;
    int right = n-1;
    int ret = 0;
    while(left<=right) {
        mid = (left+right)/2;
        if(card[mid] == key) {
            ret = 1;
            break;
        }
        else {
            if(key < card[mid])
                right = mid-1;
            else
                left = mid+1;
        }
    }
    return ret;
}