#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rd;
    mt19937_64 mt(rd());

    uniform_int_distribution<int> range(1,999999);

    int a=1;

    cout << "random number generator." << endl;

    while(a==1) {
        cout << range(mt);
        cin >> a;
    }
    
    return 0;
}
