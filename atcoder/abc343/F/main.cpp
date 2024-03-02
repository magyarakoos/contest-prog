#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

ifstream f("../input");

#ifdef LOCAL
#define cin f
#endif

class SegmentTree {
private:
    vector<pair<int, int>> tree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = size(arr);
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], INT_MIN};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            updateNode(node);
        }
    }

    void updateNode(int node) {
        vector<int> values = {tree[2 * node + 1].first, tree[2 * node + 1].second,
                              tree[2 * node + 2].first, tree[2 * node + 2].second};
        sort(values.begin(), values.end(), greater<int>());
        tree[node] = {values[0], values[1]};
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = {value, INT_MIN};
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(index, value, 2 * node + 1, start, mid);
            } else {
                update(index, value, 2 * node + 2, mid + 1, end);
            }
            updateNode(node);
        }
    }

    pair<int, int> query(int l, int r, int node, int start, int end) {
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;

        pair<int, int> leftResult = query(l, r, 2 * node + 1, start, mid);
        pair<int, int> rightResult = query(l, r, 2 * node + 2, mid + 1, end);

        vector<int> values = {leftResult.first, leftResult.second, rightResult.first, rightResult.second};
        sort(rall(values));
        return {values[0], values[1]};
    }

    void update(int index, int value) {
        update(index, value, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1).second;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& e : A) cin >> e;

    SegmentTree tree(A);
}