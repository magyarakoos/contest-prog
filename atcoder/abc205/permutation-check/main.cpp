#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<bool> perm(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        if (perm[x]) {
            cout << "No";
            exit(0);
        }
        perm[x] = 1;
    }

    cout << (all_of(all(perm), [](bool b){ return b; }) ? "Yes" : "No");
}
