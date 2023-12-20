#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

using Pair = array<int, 2>;

void init() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
}

int main() {
    init();

    int N, M;
    cin >> N >> M;

    vector<Pair> TS(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> TS[i][0] >> TS[i][1];
    }

    vector<int> path;
    int i = 1, pos = 1, curr;

    while (pos < M) {
        curr = -1;

        while (i <= N && TS[i][0] <= pos) {
            if (curr == -1 || TS[curr][1] < TS[i][1]) curr = i;
            i++;
        }

        if (curr == -1) { // impossible part
            cout << -1;
            exit(0);
        }

        pos = TS[curr][1];
        path.push_back(curr);
    }

    cout << path.size() - 1 << '\n';
    for (int n : path)  {
        cout << n << ' ';
    }

    return 0;
}
