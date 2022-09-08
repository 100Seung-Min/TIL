package com.example.firsttime

fun main() {
    var list = listOf(10, 20, 30)
    println(
        """
            list size : ${list.size}
            list data : ${list[0]}, ${list[1]}, ${list[2]}
        """.trimIndent()
    )
}