### x만큼 간격이 있는 n개의 숫자
```java
class Solution {
    fun solution(x: Int, n: Int): LongArray {
        var a = x.toLong()
        var answer = LongArray(n , {i -> i * a + a})
        return answer
    }
}
```
> 해설   
> a를 long으로 변환해준다. 왜냐하면 Int는 오버플로우 되기 때문이다.   
> 받은 a를 LongArray로 저장한다.   
> LongArray(배열의 크기, {i -> i}) => index를 이용한 활동