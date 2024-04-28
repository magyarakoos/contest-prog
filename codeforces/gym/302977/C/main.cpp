#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const int INF = 1e9;
map<string, int> m {
    {"A", 0},
    {"B", 1},
    {"C", 2},
    {"AB", 3},
    {"AC", 4},
    {"BC", 5},
    {"ABC", 6}
};
map<int, string> m2 {
    {0, "A"},
    {1, "B"},
    {2, "C"},
    {3, "AB"},
    {4, "AC"},
    {5, "BC"},
    {6, "ABC"}
};

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> v(7, INF);
    while (N--) {
        int X;
        string s;
        cin >> X >> s;
        sort(all(s));
        smin(v[m[s]], X);
    }
    int res = INF;
    for (int i = 0; i < (1 << 7); i++) {
        int values = 0, curr = 0;
        for (int j = 0; j < 7; j++) {
            if ((i >> j) & 1) {
                if (v[j] == INF) {
                    values = 0;
                    break;
                }
                curr += v[j];
                for (char c : m2[j]) {
                    values |= (1 << m[string(1, c)]);
                }
            }
        }
        if (values == 0b111) {
            res = min(res, curr);
        }
    }
    cout << (res == INF ? -1 : res);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
