#include <iostream>
#include <unordered_map>
using namespace std;

int n;
int res = -100;
unordered_map<int, int> map;

int main() {
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        map[temp]++;
    }
    for (auto it : map) {
        if(it.second > n/2) {
            res = it.first;
        }
    }

    if (res == -100) {
        cout << "no" << endl;
    }
    else {
        cout << res << endl;
    }

    return 0;
}