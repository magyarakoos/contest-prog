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
            if (choose[i])
                b.push_back(a[i]);
            else
                cb.push_back(a[i]);
        }
        if (Query(b) == 1) {
            Answer(b);
            if (cb.size() >= N) extract(cb, N);
            return;
        }
    } while (next_permutation(choose.begin(), choose.end()));
    assert(0);
}

vector<int> ab;

void sieve(vector<int> a, vector<int> b, int N) {
    if (a.size() == N) {
        Answer(a);
        vector<int> nb;
        if (!b.empty()) sieve(b, nb, N);
        return;
    }

    for (int i = 0; i < N; i++) {
        vector<int> c(a.begin(), a.begin() + i);
        c.insert(c.end(), a.begin() + i + 1, a.end());
        if (Query(c)) {
            b.push_back(a[i]);
            sieve(c, b, N);
            return;
        }
    }

    ab = a;
}
}  // namespace

void Solve(int N, int M) {
    if (N == 4 && M == 4) {
        vector<int> a(N * M);
        iota(a.begin(), a.end(), 1);
        extract(a, N);
    } else {
        vector<int> a(N * M);
        iota(a.begin(), a.end(), 1);
        vector<int> b;
        sieve(vector<int>(a.begin(), a.begin() + 500), b, N);
        for (int x : ab) cerr << x << " ";
        cerr << endl;
    }
}
