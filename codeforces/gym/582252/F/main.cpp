#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

bitset<MAXN> s;
vector<int> m[MAXN];

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    for (int i = 2; i < MAXN; i++) {
        if (!s[i]) {
            for (int j = i; j < MAXN; j += i) {
                s[j] = 1;
                m[j].push_back(i);
            }
        }
    }
    int N;
    cin >> N;
    vector ans(N, vector<int>(2, -1));
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        for (int y : m[x]) {
            for (int z : m[x]) {
                if (gcd(x, y + z) == 1) ans[i] = {y, z};
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
