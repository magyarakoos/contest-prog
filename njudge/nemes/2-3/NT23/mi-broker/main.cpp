#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> priceS(N);
    for (int i = 0; i < N; i++) {
        cin >> priceS[i];
    }

    while (Q--) {
        int result = 0;

        bool has = 0;

        int V, E;
        cin >> V >> E;

        for (int i = 0; i < N; i++) {
            if (!has && V >= priceS[i]) {
                has = 1;
                result -= priceS[i];
            }
            else if (has && E <= priceS[i]) {
                has = 0;
                result += priceS[i];
            }
        }

        cout << result << '\n';
    }
}