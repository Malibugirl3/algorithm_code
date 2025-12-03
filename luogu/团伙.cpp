#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DSU{
    int n;
    vector<int> fa;
    vector<int> enemy;

    DSU(int n) : n(n), fa(n+1), enemy(n+1, 0) {
        for(int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    int unite(int x, int y) {
        if(x==0 || y==0) return x ^ y;
        x = find(x); y = find(y);
        if(x == y) return x;

        fa[y] = x;
        return x;
    }

    bool setFriend(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra == rb) return true;
        if(enemy[ra] && find(enemy[ra]) == rb) return false;
        int newRoot = unite(ra, rb);
        int ea = enemy[ra];
        int eb = enemy[rb];
        int newEnemy = unite(ea ? find(ea) : 0, eb ? find(eb) : 0);
        if(newEnemy) {
            enemy[newRoot] = find(newEnemy);
            enemy[enemy[newRoot]] = newRoot;
        }
        else {
            enemy[newRoot] = 0;
        }
        return true;
    }

    bool setEnemy(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra == rb) return false;
        int ea = enemy[ra];
        int eb = enemy[rb];
        if(!ea) {
            enemy[ra] = rb;
        }
        else {
            int merged = unite(ea, rb);
            enemy[find(merged)] = find(merged);
        }

        if(!eb) {
            enemy[rb] = ra;
        }
        else {
            int merged = unite(eb, ra);
            enemy[find(merged)] = find(merged);
        }

        ra = find(ra);rb = find(rb);
        if(enemy[ra]) enemy[ra] = find(enemy[ra]);
        if(enemy[rb]) enemy[rb] = find(enemy[rb]);
        if(enemy[ra]) enemy[enemy[ra]] = ra;
        if(enemy[rb]) enemy[enemy[rb]] = rb;

        enemy[ra] = rb;
        enemy[rb] = ra;

        return true;
    }



};


int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--) {
        char op;
        int p, q;
        cin >> op >> p >> q;
        if(op == 'F') dsu.setFriend(p, q);
        if(op == 'E') dsu.setEnemy(p, q);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dsu.find(i) == i) ans++;
    }

    cout << ans << endl;
    return 0;
}