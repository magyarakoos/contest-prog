#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int M, N;
    cin >> M >> N;

    map<int, int> m;

    for (int i = 0; i < N; i++) {

        int E, V;
        cin >> E >> V;

        E = M - E;
        V = M - V;

        m[E]++;
        m[V]--;
    }

    int mx = 0, t = 0, curr = 0;

    for (auto [k, v] : m) {
        curr += v;
        
        if (mx < curr) {
            mx = curr;
            t = k;
        }
    }

    cout << mx << '\n' << -(t - M);
}
