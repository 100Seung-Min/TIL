### a와 b 출력하기
```java
fun main(args: Array<String>) {
    val (a, b) = readLine()!!.split(' ').map(String::toInt)
    print("a = $a\nb = $b")
}
```