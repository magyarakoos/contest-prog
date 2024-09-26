#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    priority_queue<array<int, 2>, vector<array<int, 2>>,
                   greater<array<int, 2>>>
        pq;

    while (N--) {
        int E, V;
        cin >> E >> V;
        pq.push({V, E});
    }

    vector<int> result({0});
    while (!pq.empty()) {
        auto [v, e] = pq.top();
        pq.pop();
        if (e > result.back()) { result.push_back(v - 1); }
    }

    cout << result.size() - 1 << '\n';
    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}
