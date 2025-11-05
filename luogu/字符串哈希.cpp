#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

typedef unsigned long long ULL;
vector<string> v;
const int P = 131;

ULL get_hash(const string &s) {
    ULL h = 0;
    for(char c : s) {
        h += h * P + c;
    }
    return h;
}

int main() {

    int N;
    cin >> N;

    unordered_set<ULL> hash_set;

    while(N--) {
        string s;
        cin >> s;
        hash_set.insert(get_hash(s));    
    }

    cout << hash_set.size() << endl;
    return 0;
}