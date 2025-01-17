#include <iostream>
using namespace std;

inline constexpr int MAXN = 7368790, MAXK = 5e6;

int a[MAXN], b[MAXK], bp = 0;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    a[0] = a[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[j] = 1;
            }
            b[bp++] = i;
        }
        cout << a[i];
    }
}
