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
    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        while (F--) {
            int S, EAi, MEi;
            cin >> S >> EAi >> MEi;
            bevetel[i] += EAi * MEi;
            mennyiseg[S - 1][0] += MEi;

            v[i][S - 1] = max(v[i][S - 1], EAi);
        }
    }

    ll avg = accumulate(all(bevetel), 0) / N;

    vector<int> p1;

    for (int i = 0; i < N; i++) {
        if (bevetel[i] > avg) {
            p1.push_back(i);
        }
    }

    for (int i = 0; i < M; i++) {
        mennyiseg[i][1] = i;
    }

    sort(rall(mennyiseg));

    vector<int> legtobb(M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            legtobb[i] = max(legtobb[i], v[j][i]);
        }
    }

    vector<int> earns(N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (v[j][i] == legtobb[i]) {
                earns[j]++;
            }
        }
    }

    int i,

    cout << size(p1) << ' ';
    for (int e : p1) cout << e + 1 << ' ';
    cout << '\n';

    cout << mennyiseg[K - 1][1] + 1 << '\n';
}