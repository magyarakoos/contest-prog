#include "dango3.h"

#include <bits/stdc++.h>
using namespace std;

namespace {
void extract(const vector<int>& a, int N) {

    assert(a.size() >= N);
    vector<bool> choose(a.size());
    for (int i = 0; i < N; i++) {
        choose[i] = 1;
    }
    reverse(choose.begin(), choose.end());

    do {
        vector<int> b, cb;
        for (int i = 0; i < a.size(); i++) {
            if (choose[i]) b.push_back(a[i]);
            else cb.push_back(a[i]);
        }
        if (Query(b) == 1) {
            Answer(b);
            if (cb.size() >= N) extract(cb, N);
            return;
        }
    } while (next_permutation(choose.begin(), choose.end()));
    assert(0);
}
}  // namespace

void Solve(int N, int M) {
    if (N == 4 && M == 4) {
        vector<int> a(N * M);
        iota(a.begin(), a.end(), 1);
        extract(a, N);
    }

    if (N == 100 && M == 10) {

    }
}
