#include <cstring>
#include <iostream>
using namespace std;

#define min(x, y) (x < y ? x : y)
#define BTR 8
#define MAXN ((int)1e6 + BTR + 1)

int n, a[MAXN], mem[MAXN];

void bubble(int l, int r) {
    int swapped = 0;
    int m = r;
    do {
        swapped = 0;
        for (int i = l + 1; i <= m; i++) {
            if (a[i - 1] > a[i]) {
                a[i] ^= a[i - 1];
                a[i - 1] ^= a[i];
                a[i] ^= a[i - 1];
                swapped = 1;
            }
        }
        m--;
    } while (swapped);
}

void merge(int l1, int r1, int l2, int r2) {
    int ol1 = l1, mi = 0;
    while (l1 <= r1 && l2 <= r2) {
        if (a[l1] < a[l2]) {
            mem[mi++] = a[l1++];
        } else {
            mem[mi++] = a[l2++];
        }
    }
    while (l1 <= r1) mem[mi++] = a[l1++];
    while (l2 <= r2) mem[mi++] = a[l2++];
    memcpy(a + ol1, mem, mi * 4);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    getnum(&n);
    for (int i = 0; i < n; i++) getnum(&a[i]);

    int real_n = n;
    if (n % BTR) n += BTR - n % BTR;

    for (int i = real_n; i < n; i++) a[i] = 2e9;

    for (int r = BTR - 1; r < n; r += BTR) {
        int l = r - BTR + 1;
        bubble(l, r);
    }

    for (int i = BTR; i < n; i *= 2) {
        for (int l = 0; l < n - 1; l += 2 * i) {
            int m = min(l + i - 1, n - 1);
            int r = min(l + 2 * i - 1, n - 1);
            merge(l, m, m + 1, r);
        }
    }

    for (int i = 0; i < real_n; i++) {
        putnum(a[i]);
        putchar(' ');
    }
    putchar('\n');

    return 0;
}
