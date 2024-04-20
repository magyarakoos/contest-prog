#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<array<int, 2>> insertion_sort(vector<int>& v) {
    vector<array<int, 2>> result;
    for (size_t i = 0; i < v.size(); i++) {
        int ptr = i;
        while (ptr && v[ptr - 1] > v[ptr]) {
            result.push_back({ptr, ptr - 1});
            swap(v[ptr], v[ptr - 1]);
            ptr--;
        }
    }
    return result;
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;
    auto result = insertion_sort(A);
    cout << result.size() << "\n";
    for (auto [l, r] : result) cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}