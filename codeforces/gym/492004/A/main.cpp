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
    
    vector<int> v(N);
    cinv(v);
    sort(all(v));

    int result = 1;    
    for (int i = 1; i < N; i++) {
        result += v[i - 1] != v[i];
    }

    cout << result;
}
