#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(M);
        cinv(a);
        cinv(b);
        sort(all(a));
        sort(rall(b));

        ll result = 0;
        int left = 0, right = N - 1;

        while (left <= right) {
            int dl = abs(a[left] - b[left]), 
                dr = abs(a[right] - b[right + M - N]);

            if (dl < dr) {
                result += dr;
                right--;
            } else {
                result += dl;
                left++;
            }
        }

        cout << result << '\n';
    }
}
