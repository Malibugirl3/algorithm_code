#include <iostream>
#include <unordered_map>
// #include <sstream>
using namespace std;

unordered_map<char, pair<char,char>> LinkNode;

void trace(char c) {
    if(c == '*') {
        return;
    }
    cout << c;
    trace(LinkNode[c].first);
    trace(LinkNode[c].second);
}

int main() {
    int n ;
    cin >> n;
    // int m = n;
    string s;
    char root;
    for (int i = 0; i < n; i++){
        cin >> s;
        if(i == 0) {
            root = s[0];
        }
        LinkNode[s[0]] = {s[1], s[2]};
    }

    // 前序遍历

    trace(root);



    return 0;
}