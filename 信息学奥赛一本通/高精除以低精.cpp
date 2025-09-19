#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {

    char a1[101];
    int a[101], c[101], lena, b, x = 0;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));

    cin >> a1;
    cin >> b;

    lena = strlen(a1);

    for (int i = 0; i < lena; i++) {
        a[i + 1] = a1[lena - i - 1] - '0';
    }

    for (int i = lena; i >= 1; i--) {
        c[i] = (a[i] + x * 10) / b;
        x = (a[i] + x * 10) % b;
    }

    while (lena > 1 && c[lena] == 0) {
        lena--;
    }

    for(int i = lena; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    cout << x;
    cout << endl;

    return 0;
}