#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class LinkNode {
public:
    int val;   // 本身的数据
    int subtree_sum;
    int distance;
    int left,right;

    LinkNode(int v,int left,int right) : val(v), subtree_sum(0), distance(0), left(left), right(right) {}
};

int res = 2147483647;
int root;
unordered_map<int, LinkNode*> nodes;

// 返回包括自己在内的树节点值
int build_sumtree(int n) {
    int left_tree_sum=0, right_tree_sum=0;
    LinkNode* cur_node = nodes[n];
    int val = cur_node->val;
    int left = cur_node->left;
    int right = cur_node->right;

    if(left){
        LinkNode* left_node = nodes[left];
        if(left_node->subtree_sum) left_tree_sum = left_node->subtree_sum;
        else left_tree_sum = build_sumtree(left);
    }
    if(right){
        LinkNode* right_node = nodes[right];
        if(right_node->subtree_sum) right_tree_sum = right_node->subtree_sum;
        else right_tree_sum = build_sumtree(right);
    }

    cur_node->subtree_sum = val + left_tree_sum + right_tree_sum;
    return cur_node->subtree_sum;
}

// 计算根节点距离和
int calc_root_distance(int root) {
    queue<pair<LinkNode*, int>> q;
    q.push({nodes[root], 0});
    int total_distance = 0;
    while(!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();
        total_distance += node->val * depth;
        if(node->left) q.push({nodes[node->left], depth + 1});
        if(node->right) q.push({nodes[node->right], depth + 1});
    }
    nodes[root]->distance = total_distance;
    return total_distance;
}

// 计算该节点左右子节点的距离和
void calc_distance(int n, int total_sum) {
    LinkNode* cur_node = nodes[n];
    if(cur_node->left) {
        LinkNode* left_node = nodes[cur_node->left];
        left_node->distance = cur_node->distance + total_sum - 2*left_node->subtree_sum;
        if(res > left_node->distance) res = left_node->distance;
        calc_distance(cur_node->left, total_sum);
    }
    if(cur_node->right) {
        LinkNode* right_node = nodes[cur_node->right];
        right_node->distance = cur_node->distance + total_sum - 2*right_node->subtree_sum;
        if(res > right_node->distance) res = right_node->distance;
        calc_distance(cur_node->right, total_sum);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val, left, right;
        cin >> val >> left >> right;
        nodes[i] = new LinkNode(val, left, right);
    }

    // 原来的逻辑，选择子树和最大的节点为根
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        int sum = build_sumtree(i);
        if(temp < sum){
            temp = sum;
            root = i;
        }
    }

    // 计算根节点距离和
    res = calc_root_distance(root);
    calc_distance(root, nodes[root]->subtree_sum);

    cout << res << endl;
    return 0;
}
