import kotlin.math.max

fun main() {
    val T = readln().toInt()
    repeat(T) {
        val A = readln().split(" ")
        val N = A[0].toInt()
        val c = A[1][0]
        var s = readln()
        s += s

        val M = s.length
        val fc = IntArray(M)

        var i = N
        while (i < M && s[i] != 'g') i++

        for (j in i downTo 0) {
            if (s[j] == 'g') {
                fc[j] = j
            } else {
                fc[j] = fc[j + 1]
            }
        }

        var res = 0
        for (j in 0 until N) {
            if (s[j] == c) {
                res = max(res, fc[j] - j)
            }
        }

        println(res)
    }
}
