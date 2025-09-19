#include <iostream>
#include <cstring>
using namespace std;

int a[201], b[201], c[201];

void init(int a[]) {
    string s;
    cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';   // 记得转换数字减去‘0’
    }
}

void print(int a[]) {
    int *temp = a;
    while (temp[0]) {
        if (temp[temp[0]]){
            for(int i = temp[0]; i > 0; i--) {
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
}


int main() {
    init(a);
    init(b);

    c[0] = max (a[0] , b[0]);

    int temp = 0;
    for (int i = 1; i <= c[0]; i++) {
        c[i] = a[i] + b[i] + temp;
        temp = c[i] / 10;
        c[i] %= 10;
    }
    if (temp > 0) {
        c[0]++;
        c[c[0]] = temp;
    }

    print(c);

    cout << endl;

    return 0;

}