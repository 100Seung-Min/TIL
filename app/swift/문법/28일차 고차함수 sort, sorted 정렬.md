# 고차함수 sort, sorted 정렬
---
### 1. 고차함수 sort, sorted
> sort는 자신을 변형   
> sorted는 변형을 한 후 다른 곳에 저장해야 함
```swift
var myArray = [3, 4, 88, 99 5, 6, 7, 8, 10, 20, 100]

var orderedArray = myArray.sorted()

myArray.sort()

var descendingArray = myArray.sorted(by: >)

myArray.sort(by: >)
```