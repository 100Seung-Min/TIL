### OX퀴즈
```java
class Solution {
    fun solution(quiz: Array<String>): Array<String> = quiz.map { if (it.calculate()) "O" else "X" }.toTypedArray()

    fun String.calculate() = this.split(" ").let { it[4].toInt() == if (it[1] == "-") it[0].toInt() - it[2].toInt() else it[0].toInt() + it[2].toInt() }
}
```