#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

int main() {
    vector<int> m(MAXN);
    bitset<MAXN> s, has;
    for (int i = 2; i < MAXN; i++) {
        if (!s[i]) {
            for (int j = i; j < MAXN; j += i) {
                s[j] = 1;
                if (!m[j]) m[j] = i;
            }
        }
    }

    int N;
    cin >> N;
    vector ans(N, vector<int>(2, -1));
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (m[x]) ans[i] = {m[x], x / m[x]};
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < N; i++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
