#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> stopS(M + 1);

    for (int i = 0, K, stop; i < N; i++) {
        cin >> K;
        while (K--) {
            cin >> stop;
            stopS[stop].push_back(i);
        }
    }

    vector<vector<int>> g(M + 1);

    for (int stop = 1; stop <= M; stop++) {
        for (int i = 0; i < stopS[stop].size(); i++) {
            for (int j = 0; j < i; j++) {
                g[stopS[stop][i]].push_back(
                    g[stopS[stop][i]]);
            }
        }
    }
}
