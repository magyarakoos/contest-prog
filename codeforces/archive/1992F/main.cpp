#include <iostream>
#include <vector>

using namespace std;

void solve() {
    vector<int> divS;

    int N, X;
    cin >> N >> X;

    int result = 0;

    while (N--) {
        int a;
        cin >> a;
        if (X % a) continue;

        int sz = divS.size();
        while (sz--) {
            if ((long long)divS[sz] * a <= X) {
                divS.push_back(divS[sz] * a);
            }
        }
        divS.push_back(a);

        for (int d : divS) {
            if (d == X) {
                result++;
                divS = {a};
                break;
            }
        }
    }

    cout << result + !divS.empty() << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
