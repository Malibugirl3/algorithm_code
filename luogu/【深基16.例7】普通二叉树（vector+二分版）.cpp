#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

    int q;
    cin >> q;
    vector<int> a;

    while(q--) {
        int op, x, pos;
        cin >> op >> x;
        switch (op) {
            case 1: {
                pos = lower_bound(a.begin(), a.end(), x) - a.begin();
                cout << pos + 1 << endl;
                break;
            }
            case 2: {
                cout << a[x - 1] << endl;
                break;
            }
            case 3: {
                auto it = lower_bound(a.begin(), a.end(), x);
                if (it == a.begin()) {
                    cout << -2147483647 << "\n"; // 没有前驱
                } else {
                    cout << *(--it) << "\n";    // it-1
                } 
                break;
            }
            case 4: {
                auto it = upper_bound(a.begin(), a.end(), x);
                if (it == a.end()) {
                    cout << 2147483647 << "\n"; // 没有后继
                } else {
                    cout << *it << "\n";
                }
                    break;
            }
            case 5: {
                auto it = lower_bound(a.begin(), a.end(), x);
                a.insert(it, x);
                break;
            }
            default: {
                cout << "Input wrong!" << endl;
                break;
            }
        }

    }

    return 0;
}



