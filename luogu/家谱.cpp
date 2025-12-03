#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;


string find_(string& x) {
    auto it = parent.find(x);
    if(it == parent.end()) return x;

    string root = find_(it->second);
    parent[x] = root;
    return root;
}



int main() {
    string s;

    string cur_f;
    while(cin >> s) {
        if (s == "$") break;

        if(s[0] == '#') {
            cur_f = s.substr(1);
        }
        else if(s[0] =='+') {
            string child = s.substr(1);
            parent[child] = cur_f;
        }
        else if(s[0] =='?') {
            string name = s.substr(1);
            string ans = find_(name);
            cout << name << " " << ans << endl; 
        }
        
    }


    return 0;
}