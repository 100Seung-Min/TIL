# private(set)
---
### 1. private
```swift
struct MyPet {
  private (set) var name: String = "이름없음"

  var title: String = "타이틀없음"

  mutating func setName(to newName: String){
    self.name = newName
  }
}

var myPet = MyPet()

myPet.name
myPet.title
```