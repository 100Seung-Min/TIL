# Splash
---
### 스플래시란?
> 앱 시작시 잠깐 뜨는 화면
### 예시
> manifests에서 intent.action.MAIN이 적힌 부분의 name을 스플래시액티비티명으로 변경해서 사용한다.
> ```
> handler.postDelayed({
>   intent = Intent(this, 액티비티명::class.java)
>   startActivity(intent)
>   finish()
> }, 띄우는 시간)
> ```
