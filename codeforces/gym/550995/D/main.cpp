#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

bool in_triangle(vector<array<int, 2>> tri, array<int, 2> p) { return 0; }

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> ptS(N);
    for (auto& [x, y] : ptS) cin >> x >> y;

    sort(ptS.begin(), ptS.end());

    array<int, 2> a = ptS[0], b = ptS[1], c = ptS.back();

    for (int i = 2; i < N - 1; i++) {
        if (in_triangle(a, b, c, ptS[i])) {}
    }
}
