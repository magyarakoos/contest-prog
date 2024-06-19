#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector distS(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> distS[i][j];
        }
    }

    int K;
    cin >> K;

    while (K--) {
        int U, V, W;
        ll result = 0;
        cin >> U >> V >> W;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                distS[i][j] = min({distS[i][j], distS[i][U] + distS[V][j] + W,
                                   distS[i][V] + distS[U][j] + W});
                if (i < j) result += distS[i][j];
            }
        }

        cout << result << " ";
    }

    cout << "\n";
}
