#include <iostream>
#include <vector>
using namespace std;

inline constexpr int MAXN = 7368790, MAXK = 5e6;

vector<int> create(int n) {
    vector<int> a(n, 1);
    a[0] = a[1] = 0;
    for (int i = 2; i < n; i++) {
        if (a[i]) {
            for (int j = 2 * i; j < n; j += i) a[j] = 0;
        }
    }
    return a;
}

int a[MAXN], b[MAXK], bp = 0;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    a[0] = a[1] = 1;
    int result = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!a[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                a[j] = 1;
            }
            b[bp++] = i;
        }
    }
    solve();
    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        cout << b[K - 1] << "\n";
    }
}
