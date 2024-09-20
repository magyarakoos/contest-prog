#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using Point = array<int, 2>;

int turn();

bool in_triangle(vector<Point> tri, Point p) {}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pair<Point, int>> ptS(N);
    for (int i = 0; i < N; i++) {
        cin >> ptS[i].first[0] >> ptS[i].first[1];
        ptS[i].second = i;
    }

    sort(ptS.begin(), ptS.end());

    vector<Point> tri = {ptS[0].first, ptS[1].first, ptS[2].first};
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
