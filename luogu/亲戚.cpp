#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n, m, p;

void dps(int x, int y, vector<vector<int>> &v) {
    v[x][y] = 1;
    //  base
    for(int i = 1; i <= n; i++) {
        if
    }
}
int main() {


    cin >> n >> m >> p;

    v.resize(n + 1, vector<int>(n + 1) = {0});

    int x, y;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        v[x][y] = 1;
    }


    return 0;
}