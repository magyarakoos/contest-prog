#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int N;
vector<vector<int>> g;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    if (N <= 3) {
        cout << "0\n0";
        exit(0);
    }

    g.resize(N + 1);

    for (int i = 1; i < N; i++) {
        
    }

    cout << bambus() << "\n" << star();
}
