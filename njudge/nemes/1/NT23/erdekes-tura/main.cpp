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

    int N;
    cin >> N;
    vector<int> v(N);
    cinv(v);

    int l = 0, r = 1, count = 0, len = 0;

    while (r < N && v[l] == v[r]) {
        l++;
        r++;
    }

    while (r < N) {
        if ((r + 1 == N || v[r + 1] == v[r]) && r - l + 1 >= 2) {
            len = max(len, r - l + 1);
            count++;
            r += 2;
            l = r - 1;
            while (r < N && v[l] == v[r]) {
                l++;
                r++;
            }
        } else {
            r++;
        }
    }

    cout << count << '\n' << (count ? len : -1);
}
