fun main() {
    var T = readln().toInt()
    repeat (T) {
        readln()
        val A = readln().split(" ").map { it.toInt() }
        println(A.indexOfFirst { x -> A.count({it == x}) == 1 } + 1)
    }
}
