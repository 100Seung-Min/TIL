### l로 만들기
```java
class Solution {
    fun solution(myString: String): String = myString.map{if(it < 'l') 'l' else it}.joinToString("")
}
```