# 에러
---
### 1. 에러
```swift
enum MismatchError: Error {
  case nameMismatch
  case numberMismatch
}

func guessMyName(name input: String) throws {
  print("guessMyName() called")
  if input != "쩡대리" {
    print("틀렸다")
    throw MismatchError.nameMismatch
  }
  print("맞췄다")
}

try guessMyName(name: "쩡대리")
```

> 에러가 있더라도 무시하려면 try앞에 ?를 붙여준다.
> 에러가 확실히 없으면 !를 붙여준다

### 2. 에러를 잡기
```swift
do {
  try guessMyName(name: "이대리")
} catch {
  print("잡은 에러: \(error)")
}
```

### 3. 반환하는 에러
```swift
func guessMyNumber(number input: Int) throws -> Bool {
  print("guessMyName() called")
  if input != 10 {
    print("틀렸다")
    throw MismatchError.numberMismatch
  }
  print("맞췄다")
  return true
}

do {
  let receivedValue = try guessMyNumber(number: 9)
} catch {
  print("잡은 에러 \(error)")
}
```