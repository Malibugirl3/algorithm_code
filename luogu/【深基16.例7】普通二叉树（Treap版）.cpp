#include <iostream>
#include <ctime>
using namespace std;


struct Node {
    int key, pri, sz;
    Node *l, *r;

    Node(int k) : key(k), pri(rand()), sz(1), l(nullptr), r(nullptr) {};
};

int get_size(Node* o) {
    return o ? o->sz : 0;
}

void push_up(Node* o) {
    if (o) o->sz = get_size(o->l) + get_size(o->r) + 1;
}

void rotate_right(Node*& o) {
    Node* p = o->l;
    o->l = p->r;
    p->r = o;
    push_up(o);
    push_up(p);
    o = p;
}

void rotate_left(Node*& o) {
    Node* p = o->r;
    o->r = p->l;
    p->l = o;
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
        if(o->l->pri > o->pri) rotate_right(o);
    }
    else {
        insert(o->r, key);
        if(o->r->pri > o->pri) rotate_left(o);
    }
    push_up(o);
}

int get_rank(Node* o, int key) {
    if (!o) return 1;
    if (key <= o->key) return get_rank(o->l, key);
    else return get_size(o->l) + 1 + get_rank(o->r, key);
}

int get_kth(Node* o, int k) {
    if (!o) return -1;
    int left_sz = get_size(o->l);
    if (k <= left_sz) return get_kth(o->l, k);
    else if (k == left_sz + 1) return o->key;
    else return get_kth(o->r, k - left_sz - 1);
}

int get_pre(Node* o, int key) {
    int ans = -2147483647;
    while(o) {
        if(o->key < key) {
            ans = o->key;
            o = o->r;
        }
        else o = o->l;
    }
    return ans;
}

int get_suf(Node* o, int key) {
    int ans = 2147483647;
    while(o) {
        if(o->key > key) {
            ans = o->key;
            o = o->l;
        }
        else o = o->r;
    }
    return ans;
}

int main() {

    srand(time(0));

    int q;
    cin >> q;
    Node* root = nullptr;

    for(int i=0; i<q; i++) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            cout << get_rank(root, x) << "\n";
        } else if(op == 2) {
            cout << get_kth(root, x) << "\n";
        } else if(op == 3) {
            cout << get_pre(root, x) << "\n";
        } else if(op == 4) {
            cout << get_suf(root, x) << "\n";
        } else if(op == 5) {
            insert(root, x);
        }
    }
    return 0;
}