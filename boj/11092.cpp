#include <iostream>
#include <algorithm>
#include <vector>
#define SCHOOL 1
#define GATE 0
using namespace std;

int main() {
    int n, sum, *student, *where;

    cin >> n;
    student = new int[n];
    where = new int[n];

    for(int i=0;i<n;i++) {
        cin >> student[i];
    }

    sum = 0;
    sort(student, student+n);

    

}