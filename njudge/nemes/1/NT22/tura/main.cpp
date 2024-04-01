#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()


void solve() {
    int N;
    cin >> N;
vector<bool> ugly, uglyNeighbor;
vector<vector<int>> g;
    ugly.assign(N + 1, 0);
    g.assign(N + 1, vector<int>());

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        ugly[i] = A == -1;
    }

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        if (ugly[U] && ugly[V]) {
            cout << "NEM\n2\n" << U << " " << V << "\n";
            //for (i++; i < N; i++) cin >> U >> V;
            return;
        }
    }

    cout << "IGEN\n";
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
