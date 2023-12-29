#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()

using namespace std;

int main() {
    speed;

    int N, result = 0;
    cin >> N;
    vector<int> v(N);
    cinv(v);
    sort(all(v), greater<int>());
    
    for (int i = 0; i < N; i++) {
        result = max(result, (v[i] += i));
    }

    cout << result;
}
