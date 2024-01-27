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

    int N, M;
    cin >> N >> M;

    if (M == 0) {
        cout << "YES";
        exit(0);
    }
    
    vector<int> v(M);
    for (int i = 0; i < M; i++) {
        cin >> v[i];
    }

    sort(all(v));

    if (v[0] == 1 || v[M - 1] == N) {
        cout << "NO";
        exit(0);
    }

    for (int i = 2; i < M; i++) {
        if (v[i - 2] == v[i] - 2 && v[i - 1] == v[i] - 1) {
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
}
