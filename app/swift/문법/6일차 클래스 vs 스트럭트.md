# 클래스 스트럭트
---
### 1. struct 구조체
```swift
struct YoutuberClass {
  var name: String
  var subcribersCount: Int
}

var devBaek = YoutuberStruct(name: "백승민", subcribersCount: 99999)

var devBaekClone = devBaek

print("값 넣기 전 devBaekClone : \(devBaekClone.name)")

devBaekClone.name = "백승민아님"

print("값 넣은 후 devBaekClone : \(devBaekClone.name)")
print("값 넣은 후 devBaek: \(devBaek.name)")
```

### 2. class 클래스
```swift
struct YoutuberStruct {
  var name: String
  var subcribersCount: Int
}

var devBaek = YoutuberStruct(name: "백승민", subcribersCount: 99999)

var devBaekClone = devBaek

print("값 넣기 전 devBaekClone : \(devBaekClone.name)")

devBaekClone.name = "백승민아님"

print("값 넣은 후 devBaekClone : \(devBaekClone.name)")
print("값 넣은 후 devBaek: \(devBaek.name)")
```
