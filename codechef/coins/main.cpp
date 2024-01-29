#include <bits/stdc++.h>
using namespace std;

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

unordered_map<int, int> cache;

int solve(int n) {
    if (cache.count(n)) {
        return cache[n];
    }

    if (n <= 1) {
        return 0;
    }
    
    int a = n / 2, b = n / 3, c = n / 4;

    int result = max(n, solve(a) + solve(b) + solve(c));

    cache[n] = result;

    return result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N;
    while (cin >> N) {
        cout << solve(N) << '\n';
    }
}