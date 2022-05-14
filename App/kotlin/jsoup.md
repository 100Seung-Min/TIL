# jsoup이란?
HTML문서에 저장된 데이터를 구문 분석 및 추출, 조작하도록 설계된 오픈 소스 java라이브러리이다.   
이것을 통해 앱에서 HTML문서에 내용을 파싱할 수 있다.
> ## 사용방법
> 1. url로부터 html코드를 가져온다.
> ```val doc = Jsoup.connect(url).get()```
> 2. 가져오고 싶은 태그를 선택한다.
> ```val tag= doc.select("태그") //태그를 가져온다```
> ```val id = doc.select("태그#아이디") //태그 중 아이디를 가져온다```
> ```val class = doc.select("태그.클래스") // 태그 중 클래스를 가져온다```
> ```val multi = doc.selcet("태그").select("태그") //여러 태그를 가져온다```
> ```val num = doc.select("태그")[n] //태그 중 n+1번째를 가져온다```
### 주의사항
1. 비동기로 적지 않으면 오류가 발생한다.
```
// Anco라이브러리 필요
doAsync {
  코드
}
```