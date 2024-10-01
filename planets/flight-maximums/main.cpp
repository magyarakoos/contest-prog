#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int st[20][100005];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> H(N);
    for (int& x : H) cin >> x;

    copy(H.begin(), H.end(), st[0]);
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] =
                max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    while (Q--) {
        int S, K;
        cin >> S >> K;
    }
}
