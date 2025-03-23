#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    bitset<MAXN> s, has;
    map<int, vector<int>> m;
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
        if (m[a[i]].size() >= 2) {
            ans[i] = {m[a[i]][0],
                      accumulate(m[a[i]].begin() + 1,
                                 m[a[i]].end(), 1,
                                 multiplies<int>())};
        }
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
