#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 3>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        roomS;

    vector<int> result(N);
    int room_cnt = 0;

    for (auto [a, b, i] : v) {
        if (roomS.empty() || roomS.top()[0] >= a) {
            room_cnt++;
            roomS.push({b, result[i] = roomS.size() + 1});
        } else {
            int room_id = roomS.top()[1];
            roomS.pop();
            roomS.push({b, result[i] = room_id});
        }
    }

    cout << room_cnt << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
