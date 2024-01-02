#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, result = 0, amountS[5] = {100, 20, 10, 5, 1};
    cin >> N;

    int i = 0;
    while (0 < N) {
        while (N < amountS[i]) i++;
        N -= amountS[i];
        result++;
    }

    cout << result;
}
