import kotlin.math.*

fun main() {
    val T = readln().toInt()
    repeat(T) {
        val K = readln().split(" ")[1].toInt()
        val lC = IntArray(26)
        val uC = IntArray(26)
        readln().forEach { c ->
            if (c.isLowerCase()) {
                lC[c - 'a']++
            }
            else if (c.isUpperCase()) {
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
