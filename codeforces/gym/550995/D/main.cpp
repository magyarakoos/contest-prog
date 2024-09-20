#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using point;

int turn();

bool in_triangle(vector<array<int, 2>> tri, array<int, 2> p) {}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> ptS(N);
    for (auto& [x, y] : ptS) cin >> x >> y;

    sort(ptS.begin(), ptS.end());

    vector<array<int, 2>> tri = {ptS[0], ptS[1], ptS[2]};
    for (int i = 2; i < N; i++) {
        if (ptS[i][0] > ptS[0][0]) {
            tri[2] = ptS[i];
            break;
        }
    }

    for (int i = 3; i < N - 1; i++) {
        if (in_triangle(tri, ptS[i])) {
            sort(tri.begin(), tri.end());
            tri[0] = ptS[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << find(ptS.begin(), ptS.end(), tri[i]) - ptS.begin() + 1 << " ";
    }
}
