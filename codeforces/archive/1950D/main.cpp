#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#endif

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

const int MAXN = 1e5;
vector<int> bindecS;

bool isbindec(int x) {
    while (x) {
        if (x % 10 > 1) return 0;
        x /= 10;
    }
    return 1;
}

void solve() {
    int N;
    cin >> N;
    for (int x : bindecS) {
        if (N == 1) break;
        if (N % x == 0) {
            N /= x;
        }
    }
    cout << (N == 1 ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = MAXN; i >= 1; i--) {
        if (isbindec(i)) {
            bindecS.push_back(i);
        }
    }
    DB(size(bindecS));
    int T;
    cin >> T;
    while (T--) solve();
}