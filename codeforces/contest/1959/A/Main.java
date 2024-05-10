import java.util.Scanner;

public class Main {
    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = new int[100];
        for (int i = 0; i < N; i++) {
            int X = scanner.nextInt();
            a[X - 1]++;
        }
        for (int i = 0; i < 100; i++) {
            if (a[i] == 1) {
                System.out.println(i + 1);
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        while (T-- > 0) {
            solve();
        }
    }
}
