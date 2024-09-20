#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> a(N);
    for (auto& [x, y] : a) cin >> x >> y;

    sort(a.begin(), a.end());
}
