#include <iostream>
#include <queue>

using namespace std;

int N, pipe, result;

int main() {
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        cin >> pipe;
        pq.push(pipe);
    }

    vector<pair<int, int>> cuts;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        cuts.push_back({a + b, a});
        result += a + b;
    }

    cout << result << '\n';
    for (int i = cuts.size() - 1; i >= 0; i--) {
        cout << cuts[i].first << ' ' << cuts[i].second << '\n';
    }
}
