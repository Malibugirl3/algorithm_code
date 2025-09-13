#include <iostream>
#include <string>
using namespace std;

int a[31];
bool res[10] = {false, false, false, false, false, false, false, false, false, false};

void init(int a[]) {
    string s;
    cin >> s;
    a[0] = s.length();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
    for (int i = a[0]; i >= 1; i--) {
        if (a[i]) {
            return;
        }
        a[0]--;
    }
}

 int test(int a[]) {
    if (a[0] == 0) {
        return 0;
    }
    for (int k = 2; k <= 9; k++) {
        int temp = 0;

        switch(k) {
            case 2:
                // temp = a[1];  
                if(a[1] % 2 == 0) {
                    // res.push_back(k);
                    res[k] = true;
                }
                break;
            case 3:
                for (int i = 1; i <= a[0]; i++) {
                    temp += a[i];
                }
                if (temp % 3 == 0) {
                    res[k] = true;
                }
                break;
            case 4:
                // 检查最后两位数字
                temp = a[1];
                if (a[0] >= 2) {
                    temp += a[2] * 10;
                }
                if (temp % 4 == 0) {
                    res[k] = true;
                }
                break;
            case 5:
                if (a[1] % 5 == 0) {
                    // res.push_back(k);
                    res[k] = true;
                }
                break;
            case 6:
                // 能被6整除当且仅当能被2和3整除
                if (res[2] && res[3]) {
                    res[k] = true;
                }
                break;
            case 7: {
                int rem = 0;
                for (int i = a[0]; i >= 1; i--) {
                    rem = (rem * 10 + a[i]) % 7;
                }
                
                if (rem == 0) {
                    res[k] = true;
                }
                break;
            }
            case 8:
                // 检查最后三位数字
                temp = a[1];
                if (a[0] >= 2) {
                    temp += a[2] * 10;
                }
                if (a[0] >= 3) {
                    temp += a[3] * 100;
                }
                if (temp % 8 == 0) {
                    res[k] = true;
                }
                break;
            case 9:
                for (int i = 1; i <= a[0]; i++) {
                    temp += a[i];
                }
                if (temp % 9 == 0) {
                    res[k] = true;
                }
                break;
        }
    }

    return 1;
}

int main() {

    init(a);

    int flag_1 = test(a);

    bool flag = true;

    if (flag_1) {
        bool first = true;
        for (int i = 2; i <= 9; i++) {
            if(res[i]) {
                if (!first) {
                    cout << ' ';
                }
                cout << i;
                first = false;
                flag = false;
            }
        }
        if (!flag) {
            cout << endl;
        }
    }

    if (flag) {
        cout << "none" << endl;
    }

    return 0;
}
