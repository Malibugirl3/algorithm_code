#include <iostream>
#include <unordered_map>

using namespace std;



int main() {

    long long n, target;
    long long res = 0;
    cin >> n >> target;

    unordered_map<long long, long long> num_count;

    while(n--) {
        long long num;
        cin >> num;
        num_count[num]++;
    }

    for(auto t : num_count) {
        long long r = t.first + target;
        if(num_count.count(r)) {
            // cout << t.first << " " << r << endl;
            res += t.second * num_count[r];
        }
    }
    cout << res << endl;

    return 0;
}