#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> boxS(N);
    cinv(boxS);

    bool growing = 1;
    unordered_set<int> s;
    int total_size = 0, towers_count = 0, last = 0;

    for (int i = 0; i < N; i++) {
        if (s.empty()) {
            towers_count++;
            total_size += boxS[i];
            last = boxS[i];
            s.insert(boxS[i]);
            continue;
        }

        if (total_size + boxS[i] > M || has(s, boxS[i]) || (!growing  && boxS[i] > last)) {
            growing = 1;
            s.clear();
            total_size = 0;
            i--; // a következő iterációban fogunk foglalkozni az elemmel újra
            continue;
        }

        if (boxS[i] < last) {
            growing = 0;
        }

        last = boxS[i];
        total_size += boxS[i];
        s.insert(boxS[i]);
    }

    cout << N - towers_count;
}