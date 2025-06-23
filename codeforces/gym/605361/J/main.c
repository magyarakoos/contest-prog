#include <stdio.h>

const int MAXN = 1e6 + 1;

int n, a[MAXN], mem[MAXN];

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
    for (int i = 0; i < mi; i++) a[i + ol1] = mem[i];
}

void sort(int l, int r) {
    int m = (l + r) / 2;
    if (l < m) sort(l, m);
    if (m + 1 < r) sort(m + 1, r);
    merge(l, m, m + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    sort(0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}
