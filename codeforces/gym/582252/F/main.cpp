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
    vector ans(2, vector<int>(N, -1));
    for (int i = 0, x; i < N; i++) {
        for (int j = 0; j < m[x].size(); j++) {
            for (int k = j + 1; k < m[x].size(); k++) {
                if (gcd(m[x][k] + m[x][k], x) == 1) {}
            }
        }
    }
}
