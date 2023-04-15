### k의 개수
```java
class Solution {
    fun solution(i: Int, j: Int, k: Int): Int = (i..j).sumOf { it.toString().count { c -> c.digitToInt() == k } }
}
```