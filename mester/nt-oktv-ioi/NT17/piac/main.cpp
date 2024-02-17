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

    double avg = accumulate(all(bevetel), 0) / N;

    for (int i = 0; i < N; i++) {
        if ((double)bevetel[i] > avg) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';

    for (int i = 0; i < M; i++) {
        mennyiseg[i][1] = i;
    }

    sort(rall(mennyiseg));

    cout << mennyiseg[K - 1][1] - 1 << '\n';


}

3 3 2 2 1 3
3 1 100 1 2 200 0 3 300 10 3
2 2 300 1 3 200 1 1
1 2 100 20