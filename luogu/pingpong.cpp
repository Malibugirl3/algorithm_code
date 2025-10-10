#include <iostream>

using namespace std;

void panduan_11(int *a, int *b) {
    if (*a >= 11 || *b >= 11) {
        int temp  = *a - *b;
        if (temp > 0) {
            if (temp >= 2) {
                cout << *a << ":" << *b << endl;
            }
        } else {
            if (temp <= -2) {       
                cout << *a << ":" << *b << endl;
            }
        }
    }


}

int main() {



    return 0;
}