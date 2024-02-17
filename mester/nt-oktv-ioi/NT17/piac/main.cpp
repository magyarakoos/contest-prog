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
    vector<array<int, 2>> mennyiseg(M);

    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        while (F--) {
            int S, EAi, MEi;
            cin >> S >> EAi >> MEi;
            bevetel[i] += EAi * MEi;
            mennyiseg[S - 1][0] += MEi;
        }
    }

    ll avg = accumulate(all(bevetel), 0) / N;

    for (int i = 0; i < N; i++) {
        cerr << bevetel[i] << ' ';
        if (bevetel[i] > avg) {
        }
    }
    cerr << " | " << avg;
    cout << '\n';

    for (int i = 0; i < M; i++) {
        mennyiseg[i][1] = i;
    }

    sort(rall(mennyiseg));

    cout << mennyiseg[K - 1][1] - 1 << '\n';


}