# lazy
---
### 1. lazy 키워드
> 메모리를 사용할 때 올림
```swift
struct Pet {
  Pet(){
    print("Pet이 생성")
  }
}

// Pet이 생성됨
struct Friend {
  var name: String

  var pet : Pet = Pet()

  init(_ name: String)}
  self.name = name
  print("Friend가 생성")
}

// pet이 사용되지 않았으므로 메모리에 올라가지 않음
struct Friend {
  var name: String

  lazy var pet : Pet = Pet()

  init(_ name: String)}
  self.name = name
  print("Friend가 생성")
}
```