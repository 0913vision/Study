#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    for(int i=0;i<input.length();i++) {
        char c = input.at(i);
        switch(c) {
            case 'B':
                cout << 'v';
                break;
            case 'E':
                cout << "ye";
                break;
            case 'H':
                cout << 'n';
                break;
            case 'P':
                cout << 'r';
                break;
            case 'C':
                cout << 's';
                break;
            case 'Y':
                cout << 'u';
                break;
            case 'X':
                cout << 'h';
                break;
            default:
                c = tolower(c);
                cout << c;
        }
    }
    return 0;
}