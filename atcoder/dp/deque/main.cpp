#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;
map<array<int, 3>, bool> m;

bool solve(int l, int r, int turn) {
    if (m.count({l, r, turn})) return m[{l, r, turn}];

    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    
}