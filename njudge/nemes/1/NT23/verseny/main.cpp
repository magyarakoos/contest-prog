#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

using namespace std;

int N, K, A, E, B;

int main() {
    speed;

    cin >> N >> K;
    K--;
    vector<int> P(N);
    cinv(P);

    int better = 0, a_c = N / 12, e_c = N / 4, b_c = N / 2;
    for (int i = 0; i < K; i++) {
        better += (P[i] > P[K]);
    }

    if (better < a_c) A = K + 1;
    else if (better < e_c) E = K + 1;
    else if (better < b_c) B = K + 1;

    for (int i = K + 1; i < N; i++) {
        better += (P[i] > P[K]);

        if (better < a_c) A = i + 1;
        else if (better < e_c) E = i + 1;
        else if (better < b_c) B = i + 1;
    }

    cout << A << '\n' << E << '\n' << B;
}
