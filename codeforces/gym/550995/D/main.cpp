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

    vector<array<int, 3>> ptS(N);
    for (int i = 0; i < N; i++) {
        cin >> ptS[i][0] >> ptS[i][1];
        ptS[i][2] = i;
    }

    sort(ptS.begin(), ptS.end());

    vector<array<int, 3>> tri = {ptS[0], ptS[1], ptS[2]};

    for (int i = 3; i < N; i++) {
        if (in_triangle(tri, ptS[i])) {
            sort(tri.begin(), tri.end());
            tri[2] = ptS[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << find(ptS.begin(), ptS.end(), tri[i]) - ptS.begin() + 1 << " ";
    }
}
