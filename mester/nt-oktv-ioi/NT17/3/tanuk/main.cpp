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

    for (int i = 0; i < M; i++) {



        }
    }
}