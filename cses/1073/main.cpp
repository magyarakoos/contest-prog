#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> towerS;

    while (N--) {
        int x;
        cin >> x;

        auto it = lower_bound(towerS.begin(), towerS.end(), x + 1);

        if (it == towerS.end()) {
            towerS.push_back(x);
        } else {
            towerS[it - towerS.begin()] = x;
        }
    }

    cout << towerS.size();
}
