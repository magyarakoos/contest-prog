#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

vector<array<int, 2>> g;

int free_spots(int s) {
    return 
    (g[s][0] ? free_spots(g[s][0]) : 1) + 
    (g[s][1] ? free_spots(g[s][1]) : 1);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    g.resize(N + 1);

    for (int i = 2; i <= N; i++) {
        int par;
        char type;
        cin >> par >> type;
        g[par][type == 'A' ? 0 : 1] = i;
    }

    for (int i = 1; i <= N; i++) {
        cerr << i << ' ' << g[i][0] << ' ' << g[i][1] << '\n';
    }

    cout << !g[1][0] + !g[1][1] << '\n' 
         << free_spots(g[1][0]) << '\n' 
         << free_spots(g[1][1]);
}