#include <iostream>

using namespace std;

class ThreadNode {
public:
    int val;
    ThreadNode *left, *right;
    int ltag, rtag;
    ThreadNode(int v) : val(v), left(nullptr), right(nullptr), ltag(0), rtag(0) {}
};

ThreadNode* pre = nullptr;

void InThread(ThreadNode *p) {
    if(!p) return;

    InThread(p->left);

    if(p->left == nullptr) {
        p->left = pre;
        p->ltag = 1;
    }
    if(pre != nullptr && pre->right == nullptr) {
        pre->right = p;
        pre->rtag = 1;
    }
    pre = p;

    InThread(p->right);
}

void PreThread(ThreadNode *p) {
    if(!p) return;

    if(p->left == nullptr) {
        p->left = pre;
        p->ltag = 1;
    }
    if(pre != nullptr && pre->right == nullptr) {
        pre->right = p;
        pre->rtag = 1;
    }
    pre = p;

    if(p->ltag == 0) {
        PreThread(p->left);
    }
    PreThread(p->right);
}


void PostThread(ThreadNode *p) {
    if(!p) return;

    PostThread(p->left);
    PostThread(p->right);

    if(p->left == nullptr) {
        p->left = pre;
        p->ltag = 1;
    }
    if(pre!= nullptr && pre->right == nullptr) {
        pre->right = p;
        pre->rtag = 1;
    }
    pre = p;

}