#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    // a legjobboldalabbi elérési pont pozíciója
    int right = -H - 1;

    vector<int> result;

    for (int i = 0; i < N; i++) {
        // ha a jelenlegi pont már része egy elérési pont
        // hatósugarának sem
        if (right + H < v[i]) {
            // átugorjuk azokat a pontokat, amelyek a
            // következő elérési pontból még elérhetőek
            // lesznek
            int j = i;
            while (j + 1 < N && v[j + 1] <= v[i] + H) {
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
