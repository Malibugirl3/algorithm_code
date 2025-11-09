#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_map <string, int> map;

    int n;
    cin >> n;

    while(n--) {
        int op;

        cin >> op;

        if(op == 1) {
            int sc;
            string s;
            cin >> s;
            cin >> sc;
            map[s] = sc; 
            cout << "OK" <<endl;
        }
        else if(op == 2) {
            string s;
            cin >> s;
            if(map.count(s)) {
                cout << map[s] <<endl;
            }
            else {
                cout << "Not found" << endl;
            }            
        }
        else if(op == 3){
            string s;
            cin >> s;
            if(!map.count(s)) {
                cout << "Not found" << endl;
            }
            else {
                cout << "Deleted successfully" << endl;
                map.erase(s);
            }
        }
        else if(op == 4) {
            cout << map.size() << endl;
        }

    }
    return 0;
}