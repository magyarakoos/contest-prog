#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int last = 0;
    int maxi = 0, maxw = 0;

    vector<bool> waitc(100'000);
    
    for (int i = 0; i < N; i++) {
        int u, t;
        cin >> u >> t;

        if (last <= u) {
            last = u + t;
            continue;
        } else {
            last += t;
            int wait = last - u;
            if (maxw < wait) {
                maxw = wait;
                maxi = i;
            }

            for (int i = )
        }
    }

    cout << maxi + 1 << '\n';
}
