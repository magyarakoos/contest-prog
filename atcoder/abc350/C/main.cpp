#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int partition(vector<int>& v, int begin, int end) {
    int pivot = v[end];
    int i = begin - 1;

    for (int j = begin; j < end; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[end]);
    return i + 1;
}

void quick_sort(vector<int>& v, int begin, int end) {
    if (begin < end) {
        int pivotI = partition(v, begin, end);

        quick_sort(v, begin, pivotI - 1);
        quick_sort(v, pivotI + 1, end);
    }
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;
    auto result = insertion_sort(A);
    cout << result.size() << "\n";
    for (auto [l, r] : result) cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}