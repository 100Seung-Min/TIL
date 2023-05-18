### 홀수 vs 짝수
```java
class Solution {
    fun solution(num_list: IntArray): Int = num_list.filterIndexed { i, _ -> i % 2 == 0}.sum().let { if(num_list.sum() - it >= it) num_list.sum() - it else it}
}
```