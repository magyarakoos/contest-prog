#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
using namespace std;
const int INF = 1e9;

using train = array<int, 3>; // dist, pos, id

int tail(const vector<bool>& v, int M) {
    for (int i = M; i > 0; i--) {
        if (v[i]) return i;
    }
    return 0;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<train> TS(N);

    int i = 0;
    for (train& tr : TS) {
        cin >> tr[1] >> tr[0];
        tr[0] -= tr[1];
        tr[2] = ++i;
    }

    priority_queue<train> pq;
    vector<int> path;
    vector<bool> bitmask(M + 1);

    for (int pos = 0, i = 0; !bitmask[M]; i++) {
        pq.push(TS[i]);
        if (pos < TS[i][1]) {
            const train& t = pq.top();
            for (int i = t[1]; i <= t[1] + t[0]; i++) {
                bitmask[i] = 1;
            }

            pos = tail(bitmask, M);
            cout << pos << '\n';

            /*cout << t[2] << ' ' << t[1] << ' ' << t[0] << " | ";
            for (int i = 1; i <= M; i++) cout << bitmask[i] << ' ';
            cout << '\n';*/

            path.push_back(t[2]);
            pq.pop();
        }
    }

    cout << path.size() - 1 << '\n';
    return 0;
    for (int n : path)  {
        cout << n << ' ';
    }

    return 0;
}
