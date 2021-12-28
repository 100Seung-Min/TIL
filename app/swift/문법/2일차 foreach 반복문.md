# 반복문
---

### 번외
> 1. 정수 배열만들기
> ```swift
> var myArray : [Int] = []
> ```
> 2. 값 삽입
> ```swift
> var myArray : [Int] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
> ```

### 1. 기본적인 반복문
```swift
for item in myArray {
  print("item : \(item)")
}
```

### 2. where 반복문
```swift
for item in myArray where item > 5 {
  print("item : \(item)")
}
```
```swift
for item in myArray where item % 2 == 0 {
  print("item : \(item)")
}
```