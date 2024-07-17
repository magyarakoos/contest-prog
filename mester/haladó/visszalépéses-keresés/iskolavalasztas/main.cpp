#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> choiceS(N);
    vector<int> capS(M);

    for (int i = 0; i < N; i++) cin >> choiceS[i].first >> choiceS[i].second;
    for (int i = 0; i < M; i++) cin >> capS[i];

    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> a(N), b(M);
        bool ok = 1;

        for (int i = 0; i < N; i++) {
            a[i] = (mask >> i & 1 ? choiceS[i].second : choiceS[i].first);

            if ((mask >> i & 1 && !choiceS[i].second) ||
                b[a[i] - 1] == capS[a[i] - 1]) {
                goto next;
            }

            b[a[i] - 1]++;
        }

        for (int x : a) cout << x << " ";
        cout << "\n";
        return 0;

    next:
        continue;
    }

    assert(0);
}
