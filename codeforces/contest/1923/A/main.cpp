#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

bool valid(const vector<int>& v) {
    int oc = 0;
    for (int e : v) oc += e;

    int i = 0;
    for (; i < size(v); i++) {
        if (v[i]) break;
    }

    int boc = 0;

    for (; i < size(v); i++) {
        if (!v[i]) break;
        boc++;
    }

    return oc == boc;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& e : v) cin >> e;
        
        if (valid(v)) {
            cout << "0\n";
            continue;
        }

        int result = 0;

        int i = 0;
        for (; i < N; i++) {
            if (v[i]) break;
        }

        cout << result << '\n';
    }
}