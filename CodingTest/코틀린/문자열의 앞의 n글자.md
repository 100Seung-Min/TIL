### 문자열의 앞의 n글자
```java
class Solution {
    fun solution(my_string: String, n: Int): String = my_string.slice(0 until n)
}
```