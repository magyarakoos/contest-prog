#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, count = 0, most = 0, most_s = 0;
    cin >> N;
    vector<int> B(N);
    cinv(B);

    map<int, int> m;
    for (int i = 0; i < N; count++) {
        m[B[i]]++;
        i += B[i];
    }
    for (auto [s, db] : m) {
        if (most < db) {
            most = db;
            most_s = s;
        }
    }

    cout << count << '\n' << most_s;
}
