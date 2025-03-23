#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;

bitset<MAXN> s;
vector<int> m[MAXN];

int main() {
    for (int i = 2; i < MAXN; i++) {
        for (int j = i; j < MAXN * s[i]; j++) {
            s[j] = 0;
            m[j].push_back(i);
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
}
