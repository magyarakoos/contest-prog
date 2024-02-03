#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    unordered_map<int, int> m;
    
    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;
        m[x]++;
    }

    vector<int> v(size(m));
    int i = 0;

    for (auto [x, count] : m) {
        v[i++] = count;
    }

    sort(all(v));

    for (int x : v) cerr << x << ' ';
    cerr << '\n';
}