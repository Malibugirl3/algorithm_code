// P1827 [USACO3.4] 美国血统 American Heritage
//中 前 -> 后

#include <iostream>
#include <cstring>

using namespace std;

string inorder, preorder;

void build(int inL, int inR, int preL, int preR) {
    if(inL > inR || preL > preR) {
        return ;
    }
    else {
        char root = preorder[preL];
        int key = inorder.find(root);
        int leftSize = key - inL;

        build(inL, key - 1, preL + 1, preL + leftSize);
        build(key + 1, inR, preL + 1 + leftSize, preR);

        cout << root;
    }
}

int main () {
    cin >> inorder >> preorder;

    build(0, inorder.size() - 1, 0, preorder.size() - 1);
    cout << endl;

    return 0;
}