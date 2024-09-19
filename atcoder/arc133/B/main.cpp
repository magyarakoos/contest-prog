#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    map<int, int> mp, mq;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        mp[P[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> Q[i];
        mq[Q[i]] = i;
    }

    vector<array<int, 2>> a;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) { a.push_back({mp[i], mq[j]}); }
    }

    sort(a.begin(), a.end(), [](array<int, 2> x, array<int, 2> y) {
        return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
    });

    vector<array<int, 2>> lis;

    array<int, 2> tail;

    for (auto p : a) {
        auto it = lower_bound(
            lis.begin(), lis.end(), p,
            [](array<int, 2> x, array<int, 2> y) { return x[1] < y[1]; });
        if (it == lis.end()) {
            tail = p;
            lis.push_back(p);
        } else {
            lis[it - lis.begin()] = p;
        }
    }

    cout << lis.size();
}

