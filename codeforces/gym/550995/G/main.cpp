#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<array<int, 2>, int> dp;
int N;
vector<int> a;

int solve(int i, int j) {
    return 0;
}

int main() {
    cin >> N;
    a.resize(N);
    for (int& x : a) cin >> x;
    cout << solve(0, N - 1) << "\n";
}
