// a < b ->  1
// a = b ->  0
// a > b -> -1
fun cmp(a: String, b: String): Int {
    if (a == b) return 0

    val cntA = a.count { it == 'X' }
    val cntB = b.count { it == 'X' }

    val lA = a.last()
    val lB = b.last()

    if (lA == 'M') {
        return if (lB == 'S') -1 else 1
    }
    if (lB == 'M') {
        return if (lA == 'S') 1 else -1
    }

    if (lA == 'S' && lB == 'L') {
        return 1
    }
    if (lA == 'L' && lB == 'S') {
        return -1
    }

    if (lA == 'S' && lB == 'S') {
        return if (cntA > cntB) 1 else -1
    }

    return if (cntA < cntB) 1 else -1
}

fun main() {
    val T = readln().toInt()
    repeat(T) {
        val (a, b) = readln().split(" ")
        val c = cmp(a, b)
        println(if (c == 0) "=" else if (c == 1) "<" else ">")
    }
}
