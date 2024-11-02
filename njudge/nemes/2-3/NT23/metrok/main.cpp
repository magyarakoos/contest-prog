#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> stopS(M + 1), g(M + 1);
    int IndLine = 0, ErkLine = 0;
    vector<int> ind_nodeS, erk_nodeS;

    for (int i = 1, K, stop; i <= N; i++) {
        cin >> K;
        vector<int> line(K);
        for (int j = 0; j < K; j++) {
            cin >> line[j];
            stopS[line[j]].push_back(i);
            if (line[i] == Ind) IndLine = i;
            if (line[i] == Erk) ErkLine = i;
        }
    }

    if (!IndLine || !ErkLine) {
        cout << "-1\n";
        exit(0);
    }

    for (int stop = 1; stop <= M; stop++) {
        for (int i = 0; i < stopS[stop].size(); i++) {
            for (int j = 0; j < i; j++) {
                g[stopS[stop][i]].push_back(stopS[stop][j]);
                g[stopS[stop][j]].push_back(stopS[stop][i]);
            }
        }
    }
}
