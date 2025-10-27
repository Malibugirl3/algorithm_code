#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int res[3] = {0}; //  0->depth, 1->max_width, 2->distance

struct Node {
public:

    vector<int> sons;
    int father;
    int _depth;

    Node() {}
};

void bfs(vector<Node> &v) {
    // this func can solve the depth and the width

    queue<int> q; // store the nodes' indexs in the same depth
    q.push(1); // root node
    int depth = 0;

    while(!q.empty()) {
        int size = q.size();
        depth++;
        if(size > res[1]) {
            res[1] = size;
        }
        for (int i = 0; i < size; i++) {
            int node_index = q.front();
            q.pop();
            v[node_index]._depth = depth;
            for (int son : v[node_index].sons) {
                q.push(son);
            }
        }
    }

    res[0] = depth;

}

void lca(int a, int b, vector<Node> &v) {

    int dist = 0;
    //  align their depths
    while(v[a]._depth > v[b]._depth) {
        a = v[a].father;
        dist += 2;
    }
    while(v[a]._depth < v[b]._depth) {
        b = v[b].father;
        dist += 1;
    }

    while(a != b) {
        a = v[a].father;
        b = v[b].father;
        dist += 3;
    }

    res[2] = dist;
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n+1);

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].sons.push_back(b);
        tree[b].father = a;
    }

    int a, b;
    cin >> a >> b;
    // stack<int> st;
    bfs(tree);
    lca(a, b, tree);

    cout << res[0] << endl << res[1] << endl << res[2] << endl;

    return 0;
}