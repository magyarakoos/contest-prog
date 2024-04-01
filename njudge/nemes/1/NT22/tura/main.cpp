#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<bool> ugly(N + 1);
    vector<int> uglyNeighbor(N + 1);

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        ugly[i] = A == -1;
    }

    bool running = 1;
    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;

        if (ugly[U] && ugly[V] && running) {
            cout << "NEM\n2\n" << U << " " << V << "\n";
            running = 0;
        }
        if (uglyNeighbor[U] && ugly[V] && running) {
            cout << "NEM\n3\n" << uglyNeighbor[U] << " " << U << " " << V << "\n";
            running = 0;
        }
        if (uglyNeighbor[V] && ugly[U] && running) {
            cout << "NEM\n3\n" << uglyNeighbor[V] << " " << V << " " << U << "\n";
            running = 0;
        }
        
        if (ugly[U]) {
            uglyNeighbor[V] = U;
        }
        if (ugly[V]) {
            uglyNeighbor[U] = V;
        }
    }

    if (running) cout << "IGEN\n";
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
