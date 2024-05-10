import java.util.Scanner

fun solve() {
    val scanner = Scanner(System.`in`)
    var N = scanner.nextInt()
    val a = IntArray(100)
    while (N-- > 0) {
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
    var T = scanner.nextInt()
    for (i in 0 until T) solve()
}
