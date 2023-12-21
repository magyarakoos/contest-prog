#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

struct Guest {
public:
    int e;
    int v;
    bool operator()(Guest a, Guest b) {
        return a.v > b.v;
    }
};

int main() {
    speed;

    int N;
    cin >> N;

    priority_queue<Guest, vector<Guest>, Guest> pq;

    while (N--) {
        int E, V;
        cin >> E >> V;
        pq.push({E, V});
    }

    while(!pq.empty()) {
        // idk tho
        pq.pop();
    }
}
