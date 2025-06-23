#include <stdio.h>
#include <string.h>

int n, a[(int)1e6 + 1], mem[(int)1e6 + 1];

void bubble(int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j <= r && a[i] > a[j]; j++) {
            a[i] ^= a[j];
            a[j] ^= a[i];
            a[i] ^= a[j];
        }
    }
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

void sort(int l, int r) {
    if (r - l < 16) {
        bubble(l, r);
    } else {
        int m = (l + r) / 2;
        if (l < m) sort(l, m);
        if (m + 1 < r) sort(m + 1, r);
        merge(l, m, m + 1, r);
    }
}

void getnum(int* x) {
    char c;
    do { c = getchar(); } while (c < '0' || c > '9');
    while (c >= '0' && c <= '9') {
        *x *= 10;
        *x += (c - '0');
        c = getchar();
    }
}

void putnum(int x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    char buffer[10];
    int i = 0;
    while (x > 0) {
        buffer[i++] = x % 10 + '0';
        x /= 10;
    }
    for (i--; i >= 0; i--) putchar(buffer[i]);
}

int main() {
    getnum(&n);
    for (int i = 0; i < n; i++) getnum(&a[i]);

    sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        putnum(a[i]);
        putchar(' ');
    }
    putchar('\n');

    return 0;
}
