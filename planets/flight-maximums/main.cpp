#include <iostream>
using namespace std;

int st[25][100005];
int main() {
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> st[0][i];
    for (int i = 1; i < 25; i++) {
        for (int j = 1; j + (1 << i) <= N + 1; j++) {
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
