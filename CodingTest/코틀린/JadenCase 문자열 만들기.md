### Jaden Case 문자열 만들기
```java
class Solution {
    fun solution(s: String): String = s.split(" ").joinToString(" ") { it.lowercase().replaceFirstChar { it.uppercase() } }
}
```