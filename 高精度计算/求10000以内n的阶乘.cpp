#include <iostream> 
#include <string>
using namespace std;

int a[40000];
int n;



void cheng(int a[], int b) {
    int c = 0;
    for (int i = 1; i <= a[0] + 1; i++) {
        a[i] *= b;
        a[i] += c;
        c = a[i] / 10;
        a[i] %= 10;
    }
    if (a[a[0] + 1] > 0) {
        a[0]++;
    }
    while (a[a[0]] / 10) {
        a[a[0] + 1] = a[a[0]] / 10;
        a[a[0]] = a[a[0]] % 10;
        a[0]++;
    }
}

void print (int a[]) {
    for (int i = a[0]; i >=1; i--) {
        cout << a[i];
    }
    cout << endl;
}

void jiecheng(int a[], int n) {
    if (n){
        do{
            cheng(a, n);
        }while(--n);
        return;
    }
}

int main() {
    a[0] = 1;
    a[1] = 1;
    
    cin >> n;

    jiecheng(a, n);

    print(a);
}