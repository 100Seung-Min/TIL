### ad 제거하기
```java
class Solution {
    fun solution(strArr: Array<String>): Array<String> = strArr.filter{!it.contains("ad")}.toTypedArray()
}
```