### 문자열의 뒤의 n글자
```java
class Solution {
    fun solution(my_string: String, n: Int): String = my_string.slice((my_string.length - n) until my_string.length)
}
```