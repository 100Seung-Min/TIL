# enum 케이스
---
### enum이란?
> case마다 경우를 마련한 것

### 번외
> let : 상수라서 값을 수정할 수 없다.
> var : 변수라서 값을 수정할 수 있다.

### 1. enum 만들기
```swift
enum School{
  case elementary
  case middle
  case high
}
```
```swift
enum School{
  case elementary, middle, high
}
```

### 2. enum 사용
```swift
let yourSchool = School.elementary
print("yourSchool : \(yourSchool)")
print("yourSchool : ", yourSchool)
```
### 3. enum 값 사용
```swift
enum Grade : Int{
  case first = 1
  case second = 2
}

let yourGrade = Grade.second
print("yourGrade : \(yourGrade.rawValue)")
```
```swift
enum Grade : Int{
  case first = 1
  case second = 2
}

let yourGrade = Grade.second.rawValue
print("yourGrade : \(yourGrade)")
```
### 4. enum 값 사용2
```swift
enum SchoolDetail{
  case elementary(name: String)
  case middle(name: String)
  case high(name: String)
}

let yourMidlleSchoolName = SchoolDetail.middle("영암중학교")
print("yourMidlleSchoolName : \(yourMidlleSchoolName)")
```
### 5. enum func사용
```swift
enum SchoolDetail{
  case elementary(name: String)
  case middle(name: String)
  case high(name: String)

  func getName() -> String {
    switch self {
      case .elementary(let name):
        return name
      case let .middle(name):
        return name
      case .high(let name):
        return name
    }
  }
}

let yourMidlleSchoolName = SchoolDetail.middle(name: "영암중학교")
print("yourMidlleSchoolName : \(yourMidlleSchoolName.getName())")
```