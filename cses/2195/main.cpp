#include <bits/stdc++.h>
using namespace std;

bool polar(array<int, 2> a, array<int, 2> b) {
    return a < b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end(),
         [](array<int, 2> a, array<int, 2> b) {
             return a < b;
         });
}
