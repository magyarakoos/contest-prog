#include <iostream>
#include <vector>
using namespace std;

vector<int> buckets[1 << 20];
int swap[1e6 + 1];

void sort(vector<int>& a, int l, int r, vector<int>& swap) {

}

void sort(vector<int>& a) {
    vector<int> swap(a.size());

}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        buckets[x >> 10].push_back(x & ((1 << 10) - 1));
    }
    for (int i = 0; i < (1 << 20); i++) {
        sort(buckets[i]);    
    }
}
