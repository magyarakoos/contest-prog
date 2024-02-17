#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> bevetel(N);

    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        while (F--) {
            int S, EAi, MEi;
            cin >> S >> EAi >> MEi;
            bevetel[i] += EAi * MEi;
        }
    }

    ll avg = accumulate(all(bevetel), 0) / N;
}