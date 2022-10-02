# Recyclerview
---
### 1. 리사이클러뷰란?
많은 수의 데이터 집합을, 제한된 영역으로 보여주는 위젯   
리스트 뷰에 성능과 유연함을 더한 위젯
### 2. 사용방법
1. xml에 리사이클러뷰 위젯 생성
2. xml에 itemView 생성 
3. recyclerviewAdapter파일 생성
4. recylerview에 Adater연결
> xml 파일
> ```xml
> <androidx.recyclerview.widget.RecyclerView
>   android:layout_width="match_parent"
>   android:layout_height="match_parent"/>
> ```
> item_view 파일
> ```xml
> <LinearLayout
>   android:layout_width="match_parent"
>   android:layout_height="match_parent">
>   <!-- itemViewDesign-->
> </LinearLayout>
> ```
> recyclerviewAdapter
> ```kt
> class RecyclerviewAdapter: Recyclerview.Adapter<RecyclerViewAdapter.ViewHolder>{
>   class ViewHolder(view: View): Recyclerview.ViewHolder(view){
>     fun bind(data: DateType){
>       아이템 뷰 하나하나 설정
>     }
>   } 
> override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
>        val view = LayoutInflater.from(parent.context).inflate(layout이름,parent,false)
>        return RecyclerViewAdapter.ViewHolder(view)
>    }
>
>    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
>        holder.bind(itemlist[position])
>    }
>
>    override fun getItemCount(): Int = 리사이클러뷰 크기
> }
> ```
> main
> ```kt
> binding.recyclerview.apply {
>   adapter = RecyclerviewAdapter()
>   layoutManager = LinearLayoutManager(this)
> }
>```
### 3. 추가적인 설명
만약 리사이클러뷰를 가로로 배치하고 싶을때는 LinearLayoutManager(this)부분에 밑에 코드를 작성하면 된다.
```kt
LinearLayoutManager(this,Recyclerview.HORIZONTAL, false)
```