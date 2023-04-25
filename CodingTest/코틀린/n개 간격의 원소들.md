### n개 간격의 원소들
```java
class Solution {
    fun solution(num_list: IntArray, n: Int): IntArray = (0..num_list.lastIndex step n).map{num_list[it]}.toIntArray()
}
```