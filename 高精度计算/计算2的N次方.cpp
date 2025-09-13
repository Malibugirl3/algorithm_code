#include <iostream>
using namespace std;

void cheng2(int a[]) {
    int i = 0;
    while(i < 41) {
        a[i] *= 2;
        i++;
    }
    i = 0;
    while(i < 41) {
        if (a[i] >= 10) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        i++;
    }
}

void print(int a[]) {
    int i = 41;
    while (i--) {
        if (a[i] == 0) {
            continue;
        }
        else break;
    }
    i++;
    while (i--) {
        cout << a[i];
    }
    cout << endl;
}

int main() {

    int N, a[41];
    for (int i = 0; i < 41; i++) {
        a[i] = 0;
    }
    cin >> N;
    a[0] = 1;
    while (N--) {
        cheng2(a);
    }

    print (a);

    return 0;
}