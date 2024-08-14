#include <bits/stdc++.h>
using namespace std;

struct Cmp { 
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
    for (int i = 1, a; i <= N; i++) {
        cin >> a;
        pq.push({i, a});
    }

    vector<pair<int, int>> result({{0, 0}});
    int i = 0;

    while (!pq.empty()) {
        pair<int, int> next = pq.top();
        
        if (result.back().second < next.second) {
            result.push_back({next.first, ++i});
        }

        pq.pop();
    }

    cout << result.size() - 1 << '\n';
    for (int i = 1; i < result.size(); i++) {
        cout << result[i].first << ' ' << result[i].second << '\n';
    }
}
