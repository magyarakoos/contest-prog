#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

vector<array<int, 2>> res;

void put(int a, int b) {
    res.push_back({a, b});
}

void hanoi(int a, int b, int cnt) {
    if (cnt == 0) return;

}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    hanoi(1, 3, N);

    cout << sz(res) << "\n";
    for (auto [a, b] : res) cout << a << " " << b << "\n";
}