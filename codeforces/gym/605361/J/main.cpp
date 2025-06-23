#include <iostream>
#include <vector>
using namespace std;

int mem[(int)1e6 + 1];

void merge(vector<int>& a, int l1, int r1, int l2, int r2) {

    cout << l1 << " " << r1 << " " << l2 << " " << r2
         << " : ";
    for (int i = 0; i < a.size(); i++) cout << a[i];
    cout << " ";
    int mi = 0;
    while (l1 <= r1 && l2 <= r2) {
        if (a[l1] < a[l2]) {
            mem[mi++] = a[l1++];
        } else {
            mem[mi++] = a[l2++];
        }
    }
    while (l1 <= r1) mem[mi++] = a[l1++];
    while (l2 <= r2) mem[mi++] = a[l2++];

    for (int i = 0; i < mi; i++) a[i] = mem[i];
    for (int i = 0; i < a.size(); i++) cout << a[i];
    cout << "\n";
}

void sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        sort(a, l, m);
        sort(a, m + 1, r);

        merge(a, l, m, m + 1, r);
    }
}

void sort(vector<int>& a) {
    sort(a, 0, a.size() - 1);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a);
    for (int x : a) cout << x << " ";
    cout << "\n";
}
