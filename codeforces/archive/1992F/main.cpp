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
        if (divS.count(X / a)) {
            divS = {a};
            result++;
            continue;
        }

        vector<int> buffer = {a};
        for (int b : divS)
            if ((long long)a * b < X) buffer.push_back(a * b);
        for (int b : buffer) divS.insert(b);
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
