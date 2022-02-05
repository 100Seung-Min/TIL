# 19일차 Set
---
### 1. Set
> 고유한 배열
```swift
var muNumberSet = Set<Int>()
myNumberSet.insert(1)
myNumberSet.insert(2)
myNumberSet.insert(2)
myNumberSet.insert(3)
myNumberSet.insert(3)

myNumberSet.count

for aNumber in myNumberSet {
  print("aNumber : ", aNumber)
}

var myFriends : Set<String> = ["철수", "영희", "수지"]
var myBestFriends : [String] = ["철수", "영희", "수지"]

myFriends.contains("철수")
myBestFriends.contains("철수")

if let indexToRemove = myFriends.firstIndex(of: "철수") {
  print("indexToRemove: " , indexToRemove)
  myFriends.remove(at: indexToRemove)
}
```