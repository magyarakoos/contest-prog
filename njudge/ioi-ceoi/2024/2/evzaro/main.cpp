#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    map<point, int> m;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        m[{X, Y}] = i;
    }
    vector<
}