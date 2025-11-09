#include <iostream>
#include <set>
#include <cmath>
using namespace std;



int main() {

    int m;
    cin >> m;

    set<int> s;

    while(m--) {
        int op;
        int x;
        cin >> op >> x;

        if(op == 1) {
            if (s.count(x)) {
                cout << "Already Exist" << endl;
            } else {
                s.insert(x);
            }
        }
        else {
            if (s.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            
            auto it = s.lower_bound(x);
            int ans;
            
            if (it == s.end()) {
                ans = *prev(it);
            }
            else if (it == s.begin()) {
                ans = *it;
            }
            else {
                int higher = *it;
                int lower = *prev(it);
                if(abs(higher - x) < abs(lower - x)) ans = higher;
                else ans = lower;
            }

            cout << ans << endl;
            s.erase(ans);
        }
    }

    return 0;
}