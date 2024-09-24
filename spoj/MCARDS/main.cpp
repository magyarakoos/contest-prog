#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    vector<array<int, 2>> a(C * N);
    for (auto& [X, Y] : a) cin >> X >> Y;

    int result = 1e9;
    vector<int> p = {1, 2, 3, 4};
    do {
        map<int, int> to;
        for (int i = 0; i < 4; i++) {
            to[i + 1] = p[i];
        }

        vector<array<int, 2>> lis;
        for (auto card : a) {
            auto it = lower_bound(lis.begin(), lis.end(), card, 
                [&](array<int, 2> x, array<int, 2> y){
                    return to[x[0]] == to[y[0]] ? x[1] < y[1] : to[x[0]] < to[y[0]];
                }
            );
            if (it == lis.end()) {
                lis.push_back(card);
            } else {
                lis[it - lis.begin()] = card;
            }
        }

        result = min(result, N * C - (int)lis.size());
    } while (next_permutation(p.begin(), p.end()));

    cout << result;
}
