#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

const int MAXN = 1e6;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    vector<int> ha(MAXN + 1), hb(MAXN + 1);
    for (int i = 0; i < M; i++) {
        hb[B[i]]++;
    }
    int a_sum = 0;
    for (int i = 0; i < M; i++) {
        if (ha[A[i]] + 1 <= hb[A[i]]) {
            ha[A[i]]++;
            a_sum++;
        }
    }

    int res = a_sum >= K;

    cout << a_sum << " ";
    
    for (int i = M; i < N; i++) {
        if(ha[A[i - M]] > 0) ha[A[i - M]]--, a_sum--;
        cerr << A[i - M] << "," << A[i] << ",";
        if (ha[A[i]] + 1 <= hb[A[i]]) {
            ha[A[i]]++;
            a_sum++;
        }
        res += a_sum >= K;
        cerr << a_sum << " ";
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}