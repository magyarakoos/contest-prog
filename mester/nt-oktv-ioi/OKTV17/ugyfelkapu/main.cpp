#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int MAXT = 5e4;

struct Guy {
    int i;
    int K;
    int T;
    bool operator()(Guy A, Guy B) {
        if (A.T > B.T) return 1;
        if (A.T < B.T) return 0;
        if (A.K > B.K) return 1;
        if (A.K < B.K) return 0;
        return A.i > B.i;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<Guy> v(N);
    vector<vector<Guy>> order(MAXT);
    for (int i = 0; i < N; i++) {
        cin >> v[i].K >> v[i].T;
        v[i].i = i;
        order[v[i].K].push_back(v[i]);
    }

    priority_queue<Guy, vector<Guy>, Guy> pq;

    bool busy = 0;
    int freeup = 0;
    int mxcnt_w = 0;
    int mxw_i = -1;
    int mxw_t = 0;
    for (int i = 1; i < MAXT; i++) {
        for (Guy g : order[i]) {
            pq.push(g);
        }
        if (i == freeup) busy = 0;
        if (!busy && !pq.empty()) {
            Guy curr = pq.top(); pq.pop();
            busy = 1;
            freeup = i + curr.T;
            int wait_time = i - curr.K;
            if (mxw_t < wait_time) {
                mxw_t = wait_time;
                mxw_i = curr.i;
            }
        }
        mxcnt_w = max(mxcnt_w, size(pq));
    }

    cout << mxw_i + 1 << "\n" << mxcnt_w;
}
