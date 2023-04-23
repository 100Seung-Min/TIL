### flag에 따라 다른 값 반환하기
```java
class Solution {
    fun solution(a: Int, b: Int, flag: Boolean): Int = if (flag) a + b else a - b
}
```