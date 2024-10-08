#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> lis;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a - i > 0) {
            int j = upper_bound(lis.begin(), lis.end(), a - i) -
                    lis.begin();
            if (j == lis.size()) lis.push_back(0);
            lis[j] = a - i;
        }
    }

    cout << N - lis.size();
}

