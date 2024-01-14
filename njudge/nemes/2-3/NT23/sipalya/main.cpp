#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <numeric>
using namespace std;

using ll = unsigned long long;
#define speed cin.tie(0); ios::sync_with_stdio(0)

vector<ll> heightS;
int N, K;

int main() {
    speed;

    cin >> N >> K;

    heightS.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> heightS[i];
        heightS[i] += i;
    }

    deque<pair<int, int>> q;
    vector<ll> window_mx(N - K + 1);
    
    for (int right = 0; right < K; right++) {
        while (!q.empty() && q.back().first < heightS[right]) q.pop_back();
        q.push_back({heightS[right], right});
    }

    window_mx[0] = q.front().first;
    int p = 0;

    int left = 1, right = K;
    while (left < N - K + 1) {
        while (!q.empty() && q.front().second < left) q.pop_front();

        while (!q.empty() && q.back().first < heightS[right]) q.pop_back();

        q.push_back({heightS[right], right});

        left++;
        right++;

        window_mx[++p] = q.front().first;
    }

    ll result = ULLONG_MAX;

    vector<ll> prefix(N);
    partial_sum(heightS.begin(), heightS.end(), prefix.begin() + 1);

    for (int i = 0; i < N - K; i++) {
        result = min(
            result, 
            (window_mx[i] * K) - 
            (prefix[i + K] - prefix[i])
        );
    }

    cout << result;
}