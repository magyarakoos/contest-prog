#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
    set<int> divS;

    int N, X;
    cin >> N >> X;

    int result = 1;

    while (N--) {
        int a;
        cin >> a;
        if (X % a) continue;

        for (int d : vector<int>(divS.begin(), divS.end())) {
            if (d * a > X) continue;
            if (d * a == X) {
                result++;
                divS.clear();
                break;
            }
            divS.insert(d * a);
        }
        divS.insert(a);
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
