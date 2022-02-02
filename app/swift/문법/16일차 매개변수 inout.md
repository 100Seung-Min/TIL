# 매개변수 inout
---
### 1. inout
> 함수 안에서 매개변수를 변경 못해서 사용
```swift
불가능한 코드

func sayName(_ name: String){
  name = "백승민"
  print("안녕! 난 \(name)이라고해")
}

sayName("쩡대리")
```
```swift
가능한 코드

func sayName(_ name: inout String){
  name = "백승민"
  print("안녕! 난 \(name)이라고해")
}

var name = "쩡대리"

sayName(&name)
```