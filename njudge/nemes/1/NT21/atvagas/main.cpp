#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    if (N <= 3) {
        cout << "0\n0";
        exit(0);
    }

    vector<int> indegS(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        indegS[U]++;
        indegS[V]++;
    }

    int bambus = 0;

    for (int i = 1; i <= N; i++) {
        if (indegS[i] > 2) bambus += indegS[i] - 2;
    }

    cout << bambus << "\n" << N - 1 - *max_element(all(indegS));
}
