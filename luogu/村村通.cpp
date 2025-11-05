#include <iostream>
#include <vector>
using namespace std;


int find(vector<int> &v, int x) {
    if(v[x] == x) return x;
    return v[x] = find(v, v[x]);
}

void union_set(vector<int> &v, int x, int y) {
    int fx = find(v, x);
    int fy = find(v, y);
    if(fx != fy) v[fx] = fy; 
}

int main() {

    int n, m;
    while(cin >> n) {
        if(n == 0) {
            break;
        }
        cin >> m;
        vector<int> v(n + 1);

        for(int i = 1; i <= n; i++) v[i] = i;   // initialize

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            union_set(v, a, b);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if(v[i] == i) cnt++;
        }
        cout << "==========" << endl;
        cout << cnt - 1 << endl;
        cout << "==========" << endl;
    }

    return 0;
}