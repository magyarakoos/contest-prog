#include <iostream>

using namespace std;

int lg(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int st[25][200005];
int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> st[0][i];

    for (int i = 1; i <= lg(N); i++) {
        for (int j = 1; j + (1 << i) <= N + 1; j++) {
            st[i][j] =
                min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

