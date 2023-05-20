### x 사이의 개수
```java
class Solution {
    fun solution(myString: String): IntArray = myString.split("x").map{it.length}.toIntArray()
}
```