#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    cout << accumulate(indegS.begin(), indegS.end(), 0, 
        [](int a, int b){ return max(a - 2, 0) + max(b - 2, 0); }) << "\n"
        
}
