#include <iostream>
using namespace std;

const int MAXN = 1000;

int a[MAXN] = {1};
int main() {
    a[0] = a[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[i] = 0;
            }
        }
    }
    for (int i = 2; i < 1000; i++) {
        if (a[i]) cout << i << "\n";
    }
}
