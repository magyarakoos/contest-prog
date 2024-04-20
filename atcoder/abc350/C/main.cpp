#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<array<int, 2>> insertion_sort(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        int ptr = i;
        while (ptr && v[ptr - 1] > v[ptr]) {
            swap(v[ptr], v[ptr - 1]);
            ptr--;
        }
    }
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    map<int, int> m;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        m[A[i]] = i;
    }
    vector<array<int, 2>> result;
    
    for (auto [l, r] : result) cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}