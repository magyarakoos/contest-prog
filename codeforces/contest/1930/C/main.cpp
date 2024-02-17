#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

struct BIT {
private:
    vector<int> bit;
    int n;
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

public:
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    int query(int idx) {
        return sum(idx, idx);
    }
};


int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            v[i] += i + 1;
        }

        priority_queue<int> pq(all(v));

        BIT bit(N);

        while (!pq.empty()) {
            if (bit.query())
        }
    }
}