#include <iostream>
#include <string>
using namespace std;



int main() {

    string s;
    cin >> s;
    int mode = 1;

    if(s[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    if(s[0] == '-') {
        cout << "-";
        for(int i = s.length() - 1; i > 0; i--) {
            if(s[i] == '0' && mode) {
                continue;
            }
            else {
                mode = 0;
                cout << s[i];
            }
        }
    }
    else {
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '0' && mode) {
                continue;
            }
            else {
                mode = 0;
                cout << s[i];
            }
        }
    }

    return 0;
}