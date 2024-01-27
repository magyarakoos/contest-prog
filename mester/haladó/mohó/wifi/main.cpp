#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    int right = -H - 1; // a legjobboldalabbi elérési pont pozíciója

    vector<int> result;

    for (int i = 0; i < N; i++) {
        if (right < v[i] - H) {
            int j = i;
            while (j + 1 < N && v[j + 1] - H <= v[i]) {
                j++;
            }
            i = j;

            result.push_back(i);
            right = v[i];
        }
    }

    cout << result.size() << '\n';
    for (int x : result) cout << x + 1 << ' ';
}
