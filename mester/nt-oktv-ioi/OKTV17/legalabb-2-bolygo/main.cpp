#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int A, B, C, N;
    cin >> A >> B >> C;
    N = A + B + C;

    map<int, array<int, 2>> m;

    while (N--) {
        int K, V;
        cin >> K >> V;
        m[K][0]++;
        m[V + 1][1]++;
    }

    int curr = 0, curr_K = 0;
    vector<array<int, 2>> res;
    for (const auto& [K, D] : m) {
        auto [DK, DV] = D;
        if (DV && curr >= 2 && curr + (DK - DV) < 2) {
            res.push_back({curr_K, K - 1});
        }
        if (DK && curr < 2 && curr + (DK - DV) >= 2) {
            curr_K = K;
        }
        curr += DK - DV;
    }

    cout << size(res) << "\n";
    for (auto [K, V] : res) cout << K << " " << V << "\n";
}
