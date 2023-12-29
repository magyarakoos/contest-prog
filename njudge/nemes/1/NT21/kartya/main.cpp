#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;

int main() {
    speed;

    int N;
    cin >> N;
    vector<int> A(N);
    cinv(A);

    int sum = accumulate(all(A), 0);

    if (sum % N != 0) {
        cout << "NEM\n" << N - (sum % N);
    } else {
        cout << "IGEN\n";

        int avg = sum / N;

        for (int ax : A) {
            cout << (ax > avg ? ax - avg : 0) << ' ';
        }
    }
}
