#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a;
vector<vector<int>> dp;

int solve(int l, int r) {
    return 0;
}

int main() {
    cin >> N;

    a.resize(N);
    dp.assign(N, vector<int>(N));
    for (int& x : a) cin >> x;

    cout << solve(0, N - 1) << "\n";
}
