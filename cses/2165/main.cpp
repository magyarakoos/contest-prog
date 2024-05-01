#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> res;

void hanoi(int a, int c, int cnt) {
    if (cnt == 0) return;
    int b = 6 - (a + c);
    hanoi(a, b, cnt - 1);
    res.push_back({a, b});
    hanoi(b, c, cnt - 1);
}

int main() {
    int N;
    cin >> N;
    hanoi(1, 3, N);
    cout << sz(res) << "\n";
    for (auto [a, b] : res) cout << a << " " << b << "\n";
}
