#include <iostream>
#include <cstring>

using namespace std;

int a[201], b[201], c[201];

void init(int a[]) {
    string s;
    cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
}

void print(int a[]) {
    int *temp = a;
    while (temp[0]) {
        if (temp[temp[0]]) {
            for (int i = temp[0]; i >=1; i--) {
                cout << temp[i];
            }
            cout << endl;
            return;
        }
        else {
            temp[0]--;
        }
    }
    cout << 0 << endl;
    return;
}

int main() {
    init(a);
    init(b);
    c[0] = max(a[0], b[0]);

    for (int i = 1; i <= c[0]; i++) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        if (a[i] >= b[i]) {
            c[i] = a[i] - b[i];
        }
    }

    print(c);

    return 0;
    
}