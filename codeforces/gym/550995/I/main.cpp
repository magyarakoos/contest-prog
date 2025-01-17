#include <cstring>
#include <iostream>
using namespace std;

// inline constexpr int MAXN = 7368790;
const int MAXN = 100;

int a[MAXN];
int main() {
    memset(a, 1, MAXN * sizeof(int));
    a[0] = a[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[j] = 0;
            }
        }
    }
    int result = 0;
    for (int i = 2; i < MAXN; i++) { result += a[i]; }
    cout << result << "\n";
}
