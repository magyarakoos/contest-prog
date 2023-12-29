#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()

using namespace std;
int main() {
    speed;

    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    cinv(A);
    cinv(B);

    auto it_a = min_element(all(A)), it_b = max_element(all(B));

    if (*it_b < *it_a) {
        cout << "IGEN";
    } else {
        cout << "NEM\n" << it_a - A.begin() + 1 << '\n' << it_b - B.begin() + 1;
    }
}
