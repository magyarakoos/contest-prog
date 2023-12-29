#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;
using ll = unsigned long long;

int main() {
    speed;

    ll M, X, A, B, N, K;
    cin >> M >> X >> A >> B >> N >> K;
    vector<ll> row(N);
    unordered_map<ll, ll> vis;
    bool found = 0;

    for (int i = 0; i < N; i++) {
        row[i] = i ? row[i - 1] : X;

        row[i] *= A;
        row[i] += B;

        string s = to_string(row[i]);
        while (s.size() != 4 * M) s = "0" + s;

        row[i] = stoi(s.substr(M, 2 * M));

        if (!found) {
            if (vis[row[i]]) {
                found = 1;
                cout << i + 1 - vis[row[i]] << '\n';
            } else {
                vis[row[i]] = i + 1;
            }
        }
    }

    sort(row.begin(), row.end(), greater<ll>());
    cout << row[K - 1];
}
