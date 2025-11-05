#include <iostream>
#include <unordered_map>
using namespace std;

// Union-Find
const int N = 5005;
int fa[N];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void union_set(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) fa[fx] = fy;
}


int main() {

    int n,m,p;

    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >>b;
        if(find(a) == find (b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    // unordered_map<int,int> map;
    // int a,b;
    // while(m--) {

    // }

    return 0;
}