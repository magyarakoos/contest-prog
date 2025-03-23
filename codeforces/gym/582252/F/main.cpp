#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

bitset<MAXN> s, has;
vector<int> m[MAXN];

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) {
        cin >> x;
        has[x] = 1;
    }

    for (int i = 2; i < MAXN; i++) {
        if (!s[i]) {
            for (int j = i; j < MAXN; j += i) {
                s[j] = 1;
                if (has[j]) m[j].push_back(i);
            }
        }
    }

    vector ans(N, vector<int>(2, -1));
    for (int i = 0; i < N; i++) {
        for (int y : m[a[i]]) {
            for (int z : m[a[i]]) {
                if (gcd(a[i], y + z) == 1) ans[i] = {y, z};
            }
        }
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
