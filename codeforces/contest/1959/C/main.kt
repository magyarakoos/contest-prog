import kotlin.math.abs
import kotlin.math.min

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (N, K) = readLine()!!.split(" ").map { it.toInt() }
        val lC = IntArray(26)
        val uC = IntArray(26)
        readLine()!!.forEach { c ->
            if (c.isLowerCase()) {
                lC[c - 'a']++
            } else {
                uC[c - 'A']++
            }
        }
        var res = 0
        var diffSum = 0
        for (i in 0 until 26) {
            res += min(lC[i], uC[i])
            diffSum += abs(lC[i] - uC[i]) / 2
        }
        println(res + min(diffSum, K))
    }
}
