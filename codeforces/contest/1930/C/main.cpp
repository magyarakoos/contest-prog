#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<int> BITree1, BITree2;

    BIT(int size) : n(size), BITree1(size + 1, 0), BITree2(size + 1, 0) {}

    int getSum(vector<int>& BITree, int index) {
        int sum = 0;
        index = index + 1;
        while (index > 0) {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }

    void updateBIT(vector<int>& BITree, int index, int val) {
        index = index + 1;
        while (index <= n) {
            BITree[index] += val;
            index += index & (-index);
        }
    }

    void updateRange(int l, int r, int val) {
        updateBIT(BITree1, l, val);
        updateBIT(BITree1, r + 1, -val);

        updateBIT(BITree2, l, val * (l - 1));
        updateBIT(BITree2, r + 1, -val * r);
    }

    int sum(int x) {
        return (getSum(BITree1, x) * x) - getSum(BITree2, x);
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int& e : v) cin >> e;
        

    }
}