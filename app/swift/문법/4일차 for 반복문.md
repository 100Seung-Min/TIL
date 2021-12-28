# for 반복문
---
### 1. 일반적인 for문
```swift
for i in 0...5 {
  print("i : \(i)")
}
```
### 2. 미만 for문
```swift
for i in 0..<5 {
  print("i : \(i)")
}
```
### 3. 미만 for문(where 추가)
```swift
for i in 0..<5 where i % 2 == 0{
  print("i : \(i)")
}
```
### 4. i없는 for문
```swift
var randomInts: [Int] = []
var randomInts: [Int] = [Int]()

for _ in 0..<25 {
  let randomNumber = Int.random(in: 0...100)
  randomInts.append(randomNumber)
}
print("randomInts : \(randomInts)")
```