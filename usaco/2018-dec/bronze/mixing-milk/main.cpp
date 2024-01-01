#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    array<int, 3> C, M;
    cin >> C[0] >> M[0] >> C[1] >> M[1] >> C[2] >> M[2];

    int a = 0, b = 0;

    for (int pc = 0; pc < 100; pc++) {
        b = (a + 1) % 3;

        int free_sp = C[b] - M[b];

        if (free_sp - M[a] < 0) {
            M[a] -= free_sp;
            M[b] = C[b];
        } else {
            M[b] += M[a];
            M[a] = 0;
        }

        a = b;
    }

    cout << M[0] << '\n' << M[1] << '\n' << M[2];
}
