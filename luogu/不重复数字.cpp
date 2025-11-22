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

        unordered_set<int> seen;  
        vector<int> result;       

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!seen.count(x)) { 
                seen.insert(x);
                result.push_back(x);
            }
        }


        for (int i = 0; i < result.size(); i++) {
            if (i) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}
