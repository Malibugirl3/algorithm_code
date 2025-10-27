#include <iostream>
#include <string>
using namespace std;

int res = 1;
string s1;
string s2;

void dfs(int l1,int r1,int l2,int r2) {
    if(l1 >= r1 || l2 >= r2) {
        return;
    }
    char leftRoot = s1[l1 + 1];
    int post_pos = s2.find(leftRoot, l2);

    int leftSize = post_pos - l2 + 1;
    int rightSize = r1 - l1 - leftSize;

    if((leftSize == 0 && rightSize >= 0) || (leftSize >= 0 && rightSize == 0)) {
        res *= 2;
    }

    dfs(l1 + 1, l1 + leftSize, l2, l2 + leftSize - 1);
    dfs(l1 + 1 + leftSize, r1, l2 + leftSize, r2 - 1);
}
int main() {


    cin >> s1;
    cin >> s2;


    dfs(0, s1.size() - 1, 0, s2.size() - 1);

    cout << res << endl;

    return 0;
}