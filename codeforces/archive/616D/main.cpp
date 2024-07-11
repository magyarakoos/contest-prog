#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int& x : a) cin >> x;

    int j = 0, l = 0, r = 0, mx_l = 0, mx_r = 0;
    vector<int> cnt(MAXN + 1);

    while (r < N) {
        j += ++cnt[a[r]] == 1;
        while (j > K) {
            j -= --cnt[a[l]] == 0;
            l++;
        }
        if (r - l > mx_r - mx_l) {
            mx_l = l;
            mx_r = r;
        }
        r++;
    }

    cout << mx_l + 1 << " " << mx_r + 1 << "\n";
}
