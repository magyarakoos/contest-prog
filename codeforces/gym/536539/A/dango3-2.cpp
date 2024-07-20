#include "dango3.h"

#include <bits/stdc++.h>
using namespace std;

namespace {
    int n, m;
}  // namespace

vector<int> daq(const vector<int>& a) {
    int q = Query(a);
    if (q == 0) {
        return a;
    }
    if (q == 1) {
        vector<bool> v(a.size());
        for (int i = 0; i < n; i++) {
            v[i] = 1;
        }
        reverse(v.begin(), v.end());
        do {
            vector<int> ans;
            for (int i = 0; i < a.size(); i++) {
                if (v[i]) ans.push_back(a[i]);
            }

            int qq = Query(ans);
            if (qq == 1) {
                Answer(ans);
                vector<int> rem;
                for (int i = 0; i < a.size(); i++) {
                    if (!v[i]) rem.push_back(a[i]);
                }
                return rem;
            }
        } while (next_permutation(v.begin(), v.end()));
        assert(0);
    } else {
        int mid = a.size() / 2;
        auto b = daq(vector<int>(a.begin(), a.begin() + mid));
        auto c = daq(vector<int>(a.begin() + mid, a.end()));

        b.insert(b.end(), c.begin(), c.end());
        return daq(b);
    }
}

void Solve(int N, int M) {
    n = N, m = M;
    vector<int> a(N * M);
    iota(a.begin(), a.end(), 1);
    daq(a);
}
