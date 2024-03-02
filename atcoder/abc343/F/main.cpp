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
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = size(arr);
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(index, value, 2 * node + 1, start, mid);
            } else {
                update(index, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int l, int r, int node, int start, int end) {
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(query(l, r, 2 * node + 1, start, mid), query(l, r, 2 * node + 2, mid + 1, end));
    }

    void update(int index, int value) {
        update(index, value, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto& e : A) cin >> e;

    SegmentTree tree(A);

    
}