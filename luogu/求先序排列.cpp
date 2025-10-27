#include <iostream>
#include <string>
using namespace std;

string s1;  // 中序
string s2;  // 后序

void dfs(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return;  // ✅ 只在区间为空时返回

    char root = s2[r2];  // 后序最后一个是根
    cout << root;         // 前序：先输出根

    int index = s1.find(root, l1);  // 根在中序的位置
    int leftSize = index - l1;      // 左子树大小

    // 左子树
    dfs(l1, index - 1, l2, l2 + leftSize - 1);
    // 右子树
    dfs(index + 1, r1, l2 + leftSize, r2 - 1);
}

int main() {
    cin >> s1 >> s2;
    dfs(0, s1.size() - 1, 0, s2.size() - 1);
    cout << endl;
    return 0;
}
