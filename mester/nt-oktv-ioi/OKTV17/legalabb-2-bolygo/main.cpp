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

    map<int, int> m;

    while (N--) {
        int K, V;
        cin >> K >> V;
        m[K]++;
        m[V + 1]--;
    }

    int curr = 0, curr_K = 0;
    vector<array<int, 2>> res;
    for (const auto& [K, D] : m) {
        if (curr >= 2 && curr + D < 2) {
            res.push_back({curr_K, K - 1});
        }
        curr += D;
        curr_K = K;
    }
    
    cout << size(res) << "\n";
    for (auto [K, V] : res) cout << K << " " << V << "\n";
}
