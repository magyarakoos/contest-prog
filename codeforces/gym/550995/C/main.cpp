#include <iostream>
#include <vector>

#include <debug.h>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> a;
    for (int x = 0; (1 << x) + P <= (int)1e9; x++) {
        a.push_back((1 << x) + P);
    }
    int M = a.size();

    int result = INT_MAX;

    for (int mask = 0; mask < (1 << M); mask++) {
        long long curr = 0;
        for (int i = 0; i < M; i++) {
            if (mask >> i & 1) curr += a[i];
        }
        DB(curr);
        if (curr == N) result = min(result, __builtin_popcount(mask));
    }

    cout << (result == INT_MAX ? -1 : result);
}
