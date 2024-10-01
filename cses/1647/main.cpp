#include <iostream>

using namespace std;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int st[25][200005];
int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) cin >> st[0][i];
    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] =
                min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        int i = log2_floor(R - L + 1);
        cout << min(st[i][L], st[i][R - (1 << i) + 1]) << "\n";
    }
}

