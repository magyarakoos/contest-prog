#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;

    int MG;
    cin >> MG;
    vector EG(N + 1, vector<bool>(N + 1));
    for (int i = 0; i < MG; i++) {
        int U, V;
        cin >> U >> V;
        EG[U][V] = 1;
        EG[V][U] = 1;
    }

    int MH;
    cin >> MH;
    vector EH(N + 1, vector<bool>(N + 1));
    for (int i = 0; i < MH; i++) {
        int A, B;
        cin >> A >> B;
        EH[A][B] = 1;
        EH[B][A] = 1;
    }

    vector A(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) { cin >> A[i][j]; }
    }

    DB(MG, EG);
    DB(MH, EH);
    DB(A);

    vector<int> remap(N); // 0-index, everything else is 1-index
    iota(all(remap), 1);

    ll result = INF;
    do {
        ll curr = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (EG[i][j] != EH[remap[i - 1]][remap[j - 1]]) {
                    curr += A[min(remap[i - 1], remap[j - 1])]
                             [max(remap[i - 1], remap[j - 1])];
                }
            }
        }
        result = min(result, curr);
    } while (next_permutation(all(remap)));

    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
