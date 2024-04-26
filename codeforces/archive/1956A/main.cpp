#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

void solve() {
    int K, Q;
    cin >> K >> Q;
    set<int> s;
    while (K--) {
        int A;
        cin >> A;
        s.insert(A);
    }
    while (Q--) {
        int N;
        cin >> N;
        while (1) {
            set<int> t;
            for (int i = 1; i <= N; i++) {
                t.insert(i);
            }
            set<int> diff;
            set_difference(all(t), all(s), inserter(diff, diff.begin()));
            if (N == size(diff)) break;
            N = size(diff);
        }
        cout << N << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}