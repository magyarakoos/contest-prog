#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int N;
vector<int> degreeS;

int bambus() {
    int end_count = 0;

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

    degreeS.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        degreeS[U]++;
        degreeS[V]++;
    }

    cout << bambus() << "\n" << star();
}
