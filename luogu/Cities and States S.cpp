#include <iostream>
#include <unordered_map>
using namespace std;


int main() {

    int N;
    
    cin >> N;
    
    unordered_map<string , int> cnt;
    for (int i =0; i < N; i++) {
        string city, state;
        cin >> city >> state;
        string p = city.substr(0, 2);
        if(p == state) continue;
        string key = p + "#" + state;
        cnt[key]++;
    }
    int ans = 0;
    for (auto &kv : cnt) {
        string key = kv.first;
        int c = kv.second;

        string p = key.substr(0, 2);
        string s = key.substr(3, 2);
        string rev = s + "#" + p;
        if (cnt.count(rev)) ans += c * cnt[rev];
    }

    cout << (ans / 2) << endl;


    return 0;
}