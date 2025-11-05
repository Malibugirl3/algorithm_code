#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

set<pair<int,int>> deleted;    // when draw canvas assert whether or not 
vector<vector<char>> canvas;
int n;
int test = 0;
void draw_canvas(int nx, int ny, int rootx, int rooty){

    canvas[rootx][rooty] = 'o';
    if (nx == n) { 
        return;
    }
    // cout << (1 << 0) << endl;
    int offset = 3 * (1 << (n - nx - 1)) - 1;
    offset /= 2;
    // cout << "n = " << n << endl;
    // cout << "nx = " << nx << endl;
    // cout << "offset = " << offset << endl;

    int left_id = ny * 2 - 1;
    int right_id = ny * 2;

    if(!deleted.count({nx + 1, left_id})) {
        // draw left son

        for (int i = 1; i <= offset; i++) {
            canvas[rootx + i][rooty - i] = '/';
        }
        draw_canvas(nx + 1, left_id, rootx + offset + 1, rooty - offset - 1);
    }

    if(!deleted.count({nx + 1, right_id})) {
        // draw right son
        for (int i = 1; i <= offset; i++) {
            canvas[rootx + i][rooty + i] = '\\';
        }

        draw_canvas(nx + 1, right_id, rootx + offset + 1, rooty + offset + 1);
        
    }


    return;
    // int len = 1 << (n - nx - 1);
}

int main() {

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        deleted.insert({x, y});
    }

    int leny = 1 << (n - 2);
    leny = leny * 6 - 1;
    // cout << leny << endl;
    int lenx = leny / 2 + 1;
    // cout << 1 << " " << lenx << " " << leny << endl;
    canvas.resize(lenx + 1, vector<char>(leny + 1, ' '));

    draw_canvas(1, 1, 0, leny / 2);
    // cout << 2 << endl;

    for(int i = 0; i < lenx; i++) {
        for(int j = 0; j < leny; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }

    // cout << 3 << endl;

    return 0;
}