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

vector<ll> less_cnt(const vector<int>& v) {
	ordered_set os;
	vector<ll> result(v.size());
	for (size_t i = 0; i < v.size(); i++) {
		result[i] = os.size() - os.order_of_key(v[i] + 1);
		os.insert(v[i]);
	}
	return result;
}

vector<ll> more_cnt(const vector<int>& v) {
	ordered_set os;
	vector<ll> result(v.size());
	for (int i = v.size() - 1; ~i; i--) {
		result[i] = os.order_of_key(v[i] - 1);
		os.insert(v[i]);
	}
	return result;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int& x : v) cin >> x;
	ll result = 0;
	auto lcnt = less_cnt(v), mcnt = more_cnt(v);
	for (int i = 0; i < N; i++) {
		result += lcnt[i] * mcnt[i];
	}
	cout << result << "\n";
}
