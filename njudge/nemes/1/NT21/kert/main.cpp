#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;

int main() {
    speed;

    int M, N, P, p1 = 0, p2 = 1;
    cin >> M >> N >> P;
    vector<int> v(N);
    while (M--) {
        unordered_map<int, int> m;
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            m[v[i]]++;
        }
        for (auto [_, db] : m) {
            if (N - db < db) {
                p1++;
                break;
            }
        }
        int l = 0, r = 0;
        while (r < N - 1) {
            if (v[r + 1] != v[r]) {
                l = r + 1;
                r = l;
            } else {
                r++;
                p2 = max(p2, r - l + 1);
            }
        }
    } 

    cout << p1 << '\n' << p2;
}
