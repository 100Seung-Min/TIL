# 스트럭트 mutating
---
### 1. mutating
```swift
struct BestFriend {
  var name : String

  mutating func changeName(newName: String){
    self.name = newName
  }
}

var myFriend = BestFriend(name: "쩡대리")

myFriend.changeName(newName: "백승민")
```