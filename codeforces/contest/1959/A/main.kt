import java.util.*

fun solve() {
    val scanner = Scanner(System.`in`)
    val N = scanner.nextInt()
    val a = IntArray(100)
    repeat(N) {
        val X = scanner.nextInt()
        a[X - 1]++
    }
    for (i in 0 until 100) {
        if (a[i] == 1) {
            println(i + 1)
            return
        }
    }
}

fun main() {
    val scanner = Scanner(System.`in`)
    val T = scanner.nextInt()
    repeat(T) {
        solve()
    }
}
