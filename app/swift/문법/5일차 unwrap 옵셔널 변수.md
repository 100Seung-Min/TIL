# unwrap 옵셔널 변수
---
### 옵셔널이란?
> 값이 있을 수도 있고, 없을 수도 있는 상태
   
### 1. 옵셔널 표현
```swift
var someVariable: Int? = nil

if some Variable == nill {
  somVariable = 90
}
```
   
### 언랩핑이란?
> 감싸져 있는 것을 벗기는 것
> 옵셔널을 제거하는 행위
  
### 2. if let 언랩핑
```swift
if let otherVariable = someVariable {
  print("언래핑 되었다. 즉 값이 있다. otherVariable \(otherVariable)")
} else {
  print("값이 없다.")
}
```
   
### 3. ?? 언랩핑
```swift
someVariable = nil

let myValue = someVariable ?? 10
print("myValue \(someVariable)")
```
   
### 4. 함수 언랩핑
```swift
func unwrap(parameter: Int?){
  print("unwrap() called")
  guard let unWrappedParam = parameter else {
    return
  }
  print("unWrappedParam : \(unWrappedParam)")
}
```
   
### 보충
> 함수 호출시 라벨을 해주어야 한다.   
> ex )
> ```swift
> func function(name: String){
>     print("name: \(name)")  
>}
> 
> function(name: "백승민")
> ```
> 라벨을 하지 않으려면 앞에 _를 해준다
> ```swift
> func function(_ name: String){
>     print("name: \(name)")  
>}
> 
> function("백승민")
> ```
