### n 번째 원소부터
```java
class Solution {
    fun solution(num_list: IntArray, n: Int): IntArray = num_list.slice(n - 1..num_list.lastIndex).toIntArray()
}
```