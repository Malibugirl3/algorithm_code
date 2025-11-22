#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;


int main() {

    unordered_map<string, set<int>> map; 
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        for (int j = 0; j< n; j++) {
            string s;
            cin >> s;
            map[s].insert(i);
        }
    }

    int M;
    cin >> M;

    while(M--) {
        string target;
        cin >> target;
        for(auto v : map[target]) {
            cout << v << " ";
        }
        cout << endl;
    }


    return 0;
}