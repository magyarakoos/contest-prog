#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<array<int, 2>> movieS(N);
    multiset<int> memberS;

    for (auto& [b, a] : movieS) cin >> a >> b;
    sort(movieS.begin(), movieS.end());

    while (K--) memberS.insert(0);

    int result = 0;

    for (auto [b, a] : movieS) {
        auto it = memberS.upper_bound(a);
        if (it == memberS.begin()) continue;

        result++;
        memberS.erase(--it);
        memberS.insert(b);
    }

    cout << result << "\n";
}
