#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// int main() {
//     char a1[101], b1[101];
//     int a[101], b[101], c[202], la, lb, lc;
//     memset(a, 0, sizeof(a));
//     memset(b, 0, sizeof(b));
//     memset(c, 0, sizeof(c));
//     cin >> a1 >> b1;
//     la = strlen(a1);
//     lb = strlen(b1);
//     for(int i = 0; i < la; i++) a[i] = a1[la - 1 - i] - '0';    // 逆序存入数组
//     for(int i = 0; i < lb; i++) b[i] = b1[lb - 1 - i] - '0';
//     lc = la + lb;
//     for(int i = 0; i < la; i++){
//         // int x = 0;  // x 表示进位
//         for(int j = 0; j < lb; j++){
//             c[i + j] = a[i] * b[j] + c[i + j];
//             // x = c[i + j] / 10;
//             c[i + j] %= 10;
//         }
//         // c[i + lb] = x;
//     }
//     for (int i = 0; i < lc; i++) {
//         if(c[i] >= 10) {
//             c[i + 1] += c[i] / 10;
//             c[i] %= 10;
//         }
//     }
//     while (c[lc - 1] == 0 && lc > 1){
//         lc--;
//     }
//     for(int i = 0; i < lc; i++){
//         cout << c[lc - i - 1];
//     }
//     cout << endl;
// }

int main() {
    char a1[101], b1[101];
    int a[101], b[101], c[10001], lena, lenb, lenc;
    memset(a, 0 ,sizeof(a));
    memset(b, 0 ,sizeof(b));
    memset(c, 0 ,sizeof(c));

    scanf("%s", a1);
    scanf("%s", b1);

    lena = strlen(a1);
    lenb = strlen(b1);

    for (int i = 0; i < lena; i++) {
        a[lena - i] = a1[i] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b[lenb - i] = b1[i] - '0';
    }
    for(int i = 1; i <= lena; i++) {
        int x = 0;
        for(int j = 1; j <= lenb; j++) {
            c[i + j - 1] = a[i] * b[j] + x + c[i + j -1];
            x = c[i + j -1] / 10;
            c[i + j - 1] %= 10;
        }
        c[i + lenb] = x;
    }
    lenc = lena + lenb;
    while (lenc > 1 && c[lenc] == 0) {
        lenc--;
    }
    for (int i = 0; i < lenc; i++) {
        cout << c[lenc - i];
    }
    cout << endl;



}