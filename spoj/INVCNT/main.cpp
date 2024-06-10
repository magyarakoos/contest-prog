#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

typedef tree<
    int,
    null_type,
    std::less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

void solve() {
	int N;
	cin >> N;
	ordered_set os;
	ll result = 0;
	while (N--) {
		int x;
		cin >> x;
		auto val = os.size() - os.order_of_key(x + 1);
		if (val > 0) result += val;
		os.insert(x);
	}
	cout << result << "\n";
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();
}
