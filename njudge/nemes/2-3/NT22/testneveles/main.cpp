#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> g;
vector<bool> vis;
vector<int> order;
vector<int> indegS;

int main() {
    cin >> N >> K;

    g.resize(N + 1);
    indegS.resize(N + 1);

    while (K--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        indegS[V]++;
    }

    int s;
    for (s = 1; s <= N; s++) {
        if (!indegS[s]) break;
    }

    if (s > N) { // nem körmentes
        cout << 0;
        exit(0);
    }

    
}
