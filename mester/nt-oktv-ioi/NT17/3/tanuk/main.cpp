#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<int> beginS, endS;
int N, M;

vector<int> intvS_at(int t) {

    vector<int> result;

    for (int i = 0; i < N && t >= beginS[i]; i++) {

        if (t <= endS[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;

    beginS.resize(N);
    endS.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> beginS[i] >> endS[i];
    }

    vector<int> sus(M);

    for (int i = 0; i < M; i++) {
        cin >> sus[i];
    }

    int tot = M;
    vector<int> result; 

    for (int i = 0; i < M; i++) {

        vector<int> intvS = intvS_at(sus[i]);

        if (intvS.empty()) {
            tot--;
            continue;
        }

        int best = 0, best_i = -1;

        for (int j : intvS) {
            int k;
            for (k = i + 1; k < M; k++) {
                if (beginS[j] > sus[k] || endS[j] < sus[k]) {
                    break;
                }
            }
            if (best < k) {
                best = k;
                best_i = j;
            }
        }

        i = best - 1;
        result.push_back(best_i);
    }

    cout << tot << '\n' << size(result) << '\n';
    for (int x : result) cout << x + 1 << ' ';
    cout << '\n';
}