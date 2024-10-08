#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll& e : A) cin >> e;
    
    vector<ll> S(N - 1), T(N - 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> S[i] >> T[i];
    }

    for (int i = 0; i < N - 1; i++) {
        A[i + 1] += T[i] * (A[i] / S[i]);
    }

    cout << A[N - 1];
}
