# intent & activity
---
### 액티비티란?
> 액티비티는 자체출력기능이 없다.   
> 사용자에게 실제로 보여지는 부분은 뷰 또는 뷰그룹에 해당한다.   
> setContentView메서드가 뷰를 배치하는 명령이다.
### 인텐트란?
> 액티비티끼리 서로 호출하기 위해 필요한 통신장치
> start Activity (intent) 메서드를 사용해 액티비티를 호출한다.   
### 버튼이벤트란?
> xml에서 id로 지정한 버튼을 이용한 이벤트
> 변수명 = findViewById<종류>(R.id.버튼id)로 버튼을 생성
> 변수명.setOnClickListener(){행동}으로 버튼 이벤트 등록
### 예시
> 인텐트 하고 싶은 부분   
> ```
> intent = Intent(this, 액티비티명::class.java)
> start(intent)
> ```