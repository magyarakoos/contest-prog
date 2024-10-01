#include <iostream>

using namespace std;

int st[25][100005];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) { cin >> st[0][i]; }

    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] =
                max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (Q--) {
        int S, K;
        cin >> S >> K;
        cout << st[K][S] << "\n";
    }
}

