#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

class BIT {
private:
    vector<int> BITree;
    vector<int> lazy;

public:
    BIT(int size) {
        BITree.resize(size + 1, 0);
        lazy.resize(size + 1, 0);
    }

    void updateRange(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }

    void update(int index, int val) {
        for (; index < size(BITree); index += index & -index) {
            BITree[index] += val;
        }
    }

    void rangeUpdate(int l, int r, int val) {
        updateRange(l, r, val);
    }

    void pointUpdate(int index, int val) {
        update(index, val);
    }

    int pointQuery(int index) {
        int result = 0;
        for (; index > 0; index -= index & -index) {
            result += BITree[index];
        }
        return result;
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
        
        BIT bit(N);

    }
}