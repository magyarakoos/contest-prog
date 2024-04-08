#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5;


int N, a[MAXN + 1];

void build(const vector<int>& v, int curr, int l, int r) {
    if (l == r) {
        a[l] = v[l];
        return;
    }

    int mid = (l + r) / 2;
    build(v, curr * 2, l, r);
    build(v, curr * 2 + 1, l, r);
    a[curr] = min(a[curr * 2], a[curr * 2] + 1);
}

int min(int curr, int tl, int tr, int l, int r) {
    if ()
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int& x : v) cin >> x;


}