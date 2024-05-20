#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;

    map<int, vector<int>> m;

    while (A--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }
    while (B--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }
    while (C--) {
        int K, V;
        cin >> K >> V;
        m[K].push_back(1);
        m[V].push_back(-1);
    }

    int curr = 0, curr_K = 0;
    vector<array<int, 2>> intvS;
    for (const auto& [K, D] : m) {
        int delta = 0;
        for (int x : D) {
            delta += x;
        }
        if (curr >= 2 && curr + delta < 2) {
            intvS.push_back({curr_K, K});
        }
        curr += delta;
        curr_K = K;
    }
    
    vector<array<int, 2>> res;
    for (int i = 0; i < size(intvS); i++) {
        int K = intvS[i][0];
        while (i + 1 < size(intvS) && intvS[i][1] + 1 == intvS[i + 1][0]) {
            i++;
        }
        res.push_back({K, intvS[i][1]});
    }

    cout << size(res) << "\n";
    for (auto [K, V] : res) cout << K << " " << V << "\n";
}
