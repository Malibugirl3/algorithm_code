#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent; // parent[i]
    vector<int> rankv;  // rank for union by rank
    vector<int> parity; // parity[i] = color[i] XOR color[parent[i]]

    DSU(int n=0) { init(n); }
    void init(int n_) {
        n = n_;
        parent.assign(n+1, 0);
        rankv.assign(n+1, 0);
        parity.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            parity[i] = 0;
            rankv[i] = 0;
        }
    }

    // find with path compression; returns pair(root, parity_to_root)
    pair<int,int> findp(int x) {
        if (parent[x] == x) return {x, 0};
        auto pr = findp(parent[x]);
        parent[x] = pr.first;
        parity[x] ^= pr.second; // accumulate parity to root
        return {parent[x], parity[x]};
    }

    // unite x and y with constraint: color[x] ^ color[y] = d
    // returns true if merged successfully (or constraint consistent), false if contradiction
    bool unite(int x, int y, int d) {
        auto px = findp(x);
        auto py = findp(y);
        int rx = px.first, ry = py.first;
        int parx = px.second, pary = py.second; // parx = color[x] ^ color[rx]

        if (rx == ry) {
            // already in same component: check consistency
            return ((parx ^ pary) == d);
        }
        // union by rank
        if (rankv[rx] < rankv[ry]) {
            parent[rx] = ry;
            // set parity[rx] so that color[rx] ^ color[ry] = d ^ parx ^ pary
            parity[rx] = d ^ parx ^ pary;
        } else {
            parent[ry] = rx;
            parity[ry] = d ^ parx ^ pary;
            if (rankv[rx] == rankv[ry]) rankv[rx]++;
        }
        return true;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<Edge> edges;
    edges.reserve(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    // sort by weight descending
    sort(edges.begin(), edges.end(), [](const Edge &A, const Edge &B){
        return A.w > B.w;
    });

    DSU dsu(N);
    for (auto &e : edges) {
        // require u and v be in different colors -> d = 1
        if (!dsu.unite(e.u, e.v, 1)) {
            cout << e.w << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}
