### A로 B 만들기
```java
class Solution {
    fun solution(before: String, after: String): Int = if (String(before.toCharArray().apply { sort() }) == String(after.toCharArray().apply { sort() })) 1 else 0
}
```