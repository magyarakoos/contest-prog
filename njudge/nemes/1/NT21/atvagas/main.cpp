#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int N;
vector<set<int>> g;

int bambus() {
    
}

int star() {
    return 0;
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    if (N <= 3) {
        cout << "0\n0";
        exit(0);
    }

    g.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        g[U].insert(V);
        g[V].insert(U);
    }

    cout << bambus() << "\n" << star();
}
