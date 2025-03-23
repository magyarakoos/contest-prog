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
    vector ans(2, vector<int>(N));
    while (cin >> x && N--) {
        for (int i = 0; i < m[x].size(); i++) {
            for (int j = i + 1; j < m[x].size(); j++) {
                if (gcd(m[x][i] + m[x][j], x) == 1) {}
            }
        }
    }
}
