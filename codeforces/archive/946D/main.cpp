#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int first(const vector<bool>& v) {
    for (int i = 0; i < size(v); i++) {
        if (v[i]) {
            return i;
        }
    }
    return -1;
}

int last(const vector<bool>& v) {
    for (int i = size(v) - 1; i >= 0; i--) {
        if (v[i]) {
            return i;
        }
    }
    return -1;
}

int total(const vector<bool>& v) {
    int f = first(v),
        l = last(v);

    return (f == -1 ? 0 : l - f + 1);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<bool>> table(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char b;
            cin >> b;
            table[i][j] = b == '1';
        }
    }

    // hourS[i][j] = az i. napon j óra kihagyásával legalább hány órát kell bent lenni
    vector<vector<int>> hourS(N, vector<int>(K + 1));

    for (int i = 0; i < N; i++) {

        hourS[i][0] = total(table[i]);

        for (int j = 1; j <= K; j++) {

            int f = first(table[i]),
                l = last(table[i]);
            
            if (f == -1) {
                hourS[i][j] = 0;
                continue;
            }

            if (f == l) {
                table[i][f] = 0;
                hourS[i][j] = 0;
                continue;
            }

            table[i][f] = 0;
            int new_f = first(table[i]);
            int gain_f = new_f - f + 1;
            table[i][f] = 1;

            table[i][l] = 0;
            int new_l = last(table[i]);
            int gain_l = l - new_l + 1;
            table[i][l] = 1;

            if (gain_f < gain_l) {
                table[i][l] = 0;
            } else {
                table[i][f] = 0;
            }

            hourS[i][j] = total(table[i]);
        }
    }

    // dp[i][j] = az i. napig bezárólag, legfeljebb j óra kihagyásával
    // legalább hány órát kell bent lenni
    vector<vector<int>> dp(N, vector<int>(K + 1, INF));

    for (int i = 0; i <= K; i++) {
        dp[0][i] = hourS[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            // a j kihagyásból hányat használjunk el ma
            for (int dj = 0; dj <= j; dj++) {
                dp[i][j] = min(
                    dp[i][j],
                    hourS[i][dj] +
                    dp[i - 1][j - dj]
                );
            }
        }
    }

    cout << dp[N - 1][K];
}
