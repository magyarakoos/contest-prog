#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int& e : A) cin >> e;

        vector<int> row(N + 1);

        for (int i = 0; i < N; i++) {
            int X;
            cin >> X;
            row[abs(X)] += A[i];
        }

        int curr = 
    }
}