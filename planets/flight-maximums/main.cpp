#include <bit>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int log2_floor(unsigned i) {
    return bit_width(i) - 1;
}

int st[25][100005];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> H(N);
    for (int& x : H) cin >> x;

    copy(H.begin(), H.end(), st[0]);
    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] =
                max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (Q--) {
        int S, K;
        cin >> S >> K;
        int L = S - 1, R = S + (1 << K) - 2;

        int i = log2_floor(R - L + 1);
        cout << max(st[i][L], st[i][R - (1 << i) + 1]) << "\n";
    }
}
