### k번째 수
```java
class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = intArrayOf()
        for(i in 0..commands.size - 1){
            var array1 = intArrayOf()
            for(j in commands[i].get(0) - 1..commands[i].get(1) - 1){
                array1 = array1.plus(array[j])
            }
            array1.sort()
            answer = answer.plus(array1[commands[i].get(2) - 1])
        }
        return answer
    }
}
```
> 해설    
> commands의 사이즈 - 1 만큼 for문을 돌린다.   
> commands의 i번째 배열에서 시작과 끝을 나타내는 인덱스를 가져와 -1 한다.  
> array1의 배열에 더해준다.   
> array1을 오름차순으로 정렬한다.   
> array1의 원하는 인덱스를 가져와서 answer에 더해준다.