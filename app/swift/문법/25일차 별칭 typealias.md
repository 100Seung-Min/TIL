# 별칭 typealias
---
### 1. 별칭 typealias
> 다른 말로 사용할 수 있도록 하는 키워드   
```swift
protocol Naming {
  func getName() -> String
}

protocol Aging {
  func getAge() -> Int
}

typealias Friendable = Naming & Aging

typealias FullNaming = Naming

struct Friend : Friendable {
  var name : String
  var age: Int

  func getName() -> String {
    return self.name
  }

  func getAge() -> Int {
    return self.age
  }
}
```
   
### 2. 자료형 typealias
```swift
typealias FriendName = String

var friendName : FriendName = "백승민"

typealias Friends = [Friend]

var myFriendsArray : Friends = []

typealias StringBlock = (String) -> Void

func sayHi(completion : Stringblock) {
  completion("안녕")
}

sayHi(completion : { saying in
  print("여기서 시작 : ", saying)
})
```
   
### 3. 참조문 typealias
```swift
class MyClass {
  enum MY_TYPE {
    case DOG, CAT, BIRD
  }
  var myType = MyType.DOG
}

typealias MyType = MyClass.MY_TYPE

var myClass = MyClass()

myClass.myType = myType.DOG
```