#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector distS(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> distS[i][j];
        }
    }

    vector<int> order(N);
    for (int& x : order) cin >> x;
    reverse(all(order));

    vector FW(N + 1, vector<ll>(N + 1, INF));

    for (int x : order) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {

            }
        }
    }
}