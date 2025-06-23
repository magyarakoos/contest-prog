#include <stdio.h>
#include <string.h>

#define BUBBLE_TRESHOLD 16

int n, a[(int)1e6 + 1], mem[(int)1e6 + 1],
    lefts[(int)1e5 + 1], rights[(int)1e5 + 1];

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
    if (n % 16) n += 16 - n % 16;

    for (int i = real_n; i < n; i++) a[i] = 2e9;

    int cnt = 0;
    for (int r = BUBBLE_TRESHOLD - 1; r < n;
         r += BUBBLE_TRESHOLD) {
        int l = r - BUBBLE_TRESHOLD + 1;
        bubble(l, r);
        lefts[cnt] = l;
        rights[cnt++] = r;
    }

    while (cnt > 1) {
        for (int i = 1; i < cnt; i += 2) {
            merge(lefts[i - 1], rights[i - 1], lefts[i],
                  rights[i]);
            lefts[i / 2] = lefts[i - 1];
            rights[i / 2] = rights[i - 1];
        }
        if (cnt % 2) {
            lefts[cnt / 2] = lefts[cnt - 1];
            rights[cnt / 2] = rights[cnt - 1];
        }
        cnt = (cnt + 1) / 2;
    }

    for (int i = 0; i < real_n; i++) {
        putnum(a[i]);
        putchar(' ');
    }
    putchar('\n');

    return 0;
}
