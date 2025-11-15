#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        unordered_set<int> seen;  // 记录出现过的数字
        vector<int> result;       // 存放输出顺序

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!seen.count(x)) { // 第一次出现
                seen.insert(x);
                result.push_back(x);
            }
        }

        // 输出
        for (int i = 0; i < result.size(); i++) {
            if (i) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}
