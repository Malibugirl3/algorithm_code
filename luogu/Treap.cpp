// Tree + Heap ———— non-same

#include <iostream>

using namespace std;

struct Node {
    int key, pri;
    int sz;
    Node *l, *r;
    Node(int k) : key(k), pri(rand()), sz(1), l(nullptr), r(nullptr){};
};

int get_size(Node* o) {
    return o ? o->sz : 0;
}

void push_up(Node* o) {
    if(o) o->sz = 1 + get_size(o->l) + get_size(o->r);
}

void rotate_right(Node*& o) {
    Node* p  = o->l;
    o->l = p->r;
    p->r = o;
    push_up(o);
    push_up(p);
    o = p;  // 根节点的父节点需要知道旋转之后的更改，简单来说就是改变原来父节点的指向
}

void rotate_left(Node*& o) {
    Node* p = o->l;
    o->l = p->r;
    p->r = o;
    push_up(o);
    push_up(p);
    o = p;
}

void insert(Node*& o, int key) {
    if(!o) {
        o = new Node(key);
        return;
    }

    if(key < o->key) {
        insert(o->l, key);
        if(o->l->pri > o->pri) {
            rotate_right(o);
        }
    }
    else {
        insert(o->r, key);
        if(o->r->pri > o->pri) {
            rotate_left(o);
        }
    }
    push_up(o);
}

int get_rank(Node* o, int key) {
    if(!o) {
        return 1;
    }
    if (key <= o->key) {
        return get_rank(o->l, key);
    }
    else {
        return 1 + get_size(o->l) + get_rank(o->r, key);
    }
}

int get_kth(Node* o, int k) {
    if(!o) return -1;
    int left_sz = o->sz;
    if(k <= left_sz) return get_kth(o->l, k);
    else if(k == left_sz + 1) return o->key;
    else return left_sz + 1 + get_kth(o->r, k - left_sz - 1);
}

int get_pre(Node* o, int key) {
    int ans = -2147483647;
    while (o) {
        if (o->key < key) {
            ans = o->key;
            o = o->r;
        }
        else {
            o = o->l;
        }
    }
    return ans;
}

int get_suf(Node* o, int key) {
    int ans = 2147483647;
    while(o) {
        if (o->key > key) {
            ans = o->key;
            o = o->l;
        }
        else {
            o = o->r;
        }
    }
    return ans;
}