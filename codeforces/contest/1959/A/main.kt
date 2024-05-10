fun main() {
    var T = readln().toInt()
    repeat (T) {
        val N = readln().toInt()
        val A = readln().split(" ").map { it.toInt() }
        println(A.indexOfFirst { x -> a.count(it == x) == 1 } + 1)
    }
}
