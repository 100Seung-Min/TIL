### qr code
```java
class Solution {
    fun solution(q: Int, r: Int, code: String): String = code.filterIndexed{i, _ -> i % q == r}
}
```