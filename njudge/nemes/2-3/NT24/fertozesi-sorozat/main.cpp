#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> a(K);
    for (int& x : a) cin >> x;

    vector<vector<int>> g(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<int> result;
    for (int start = 1; start <= N; start++) {}

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
