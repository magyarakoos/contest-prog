#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
#define int long long

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int& x : p) cin >> x;

    int goal = N * K;
    int avg = accumulate(p.begin(), p.end(), 0LL);

    if (goal == avg) {
        cout << "0\n";
        exit(0);
    }

    int l = 0, r = 1e15;
}
