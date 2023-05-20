### n 번째 원소까지
```java
class Solution {
    fun solution(num_list: IntArray, n: Int): IntArray = num_list.slice(0 until n).toIntArray()
}
```