#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int H = N / 2 + (N & 1);

    unordered_map<int, int> front, back;

    for (int i = 0; i < N; i++) {
        int f, b;
        cin >> f >> b;
        front[f]++;
        if (f != b) back[b]++;
    }

    int result = INT_MAX;

    for (auto [fcolor, fcount] : front) {
        if (fcount >= H) {
            cout << 0;
            exit(0);
        }

        if (!back.count(fcolor)) {
            continue;
        }

        int bcount = back[fcolor];

        if (fcount + bcount < H) {
            continue;
        }

        result = min(result, H - fcount);
    }

    for (auto [bcolor, bcount] : back) {
        if (bcount >= H) {
            result = min(result, H);
            break;
        }
    }

    cout << (result == INT_MAX ? -1 : result);
}