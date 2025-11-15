#include <iostream>
#include <unordered_map>
using namespace std;


int main() {

    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x] = i;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int y;
        cin >> y;
        if (mp.count(y)) {
            cout << mp[y] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}