#include <stdio.h>

#define min(x, y) (x < y ? x : y)
#define BTR 4
#define MAXN ((int)1e6 + BTR + 1)

int n, a[MAXN], mem[MAXN];

void bubble(int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int key = a[i], j = i - 1;
        while (j >= l && a[j] > key) a[j + 1] = a[j--];
        a[j + 1] = key;
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
    for (int i = 0; i < mi; i++) a[ol1 + i] = mem[i];
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
