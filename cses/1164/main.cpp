#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Room {
    int b, id;
    bool operator<(Room r) const { return b < r.b; }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 3>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][1] >> v[i][0];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());

    multiset<Room> roomS;
    roomS.insert({0, 1});

    vector<int> result(N);

    for (auto [b, a, i] : v) {
        auto it = roomS.upper_bound({a, 0});
        assert(it != roomS.end());
        for (Room r : roomS) cout << r.b << "," << r.id << " ";
        cout << "\n";

        if (it == roomS.begin()) {
            cout << "WA\n";
            result[i] = roomS.size() + 1;
        } else {
            cout << "AC\n";
            it--;
            result[i] = (*it).id;
            roomS.erase(it);
        }

        roomS.insert({b, result[i]});
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}
