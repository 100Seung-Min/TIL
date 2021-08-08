# viewpager
---
# 하는 법
1. fragment파일을 생성한다. (원하는 화면만큼)
2. adapter파일을 만들어준다.
3. viewpager를 할 activity에 adapter을 연결한다.
---
### 상세내용
1. fragment
```
override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
}

override fun onCreateView(
    inflater: LayoutInflater, container: ViewGroup?,
    savedInstanceState: Bundle?
): View? {
    // Inflate the layout for this fragment
    return inflater.inflate(R.layout.fragment_first, container, false)
}

override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
    super.onViewCreated(view, savedInstanceState)

    val page = view?.findViewById<ImageView>(R.id.page)
    page.setOnClickListener {
        if(i == 0){
            page.setImageResource(R.drawable.ic_launcher_foreground)
            i = 1;
        }
        else {
            page.setImageResource(R.drawable.nature)
            i = 0;
        }
    }
}
```
2. adapter
```
class Adapter(fragmentManager: FragmentManager, lifecycle: Lifecycle : FragmentStateAdapter(fragmentManager, lifecycle) {
    override fun getItemCount(): Int {
        return 3
    }

    override fun createFragment(position: Int): Fragment {
        return when(position){
            0 -> {
                FirstFragment()
            }
            1 -> {
                SecFragment()
            }
            2 -> {
                ThirdFragment()
            }
            else -> {
                Fragment()
            }
        }
    }
}
```
3. activity
```
override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)

    val viewPager2=findViewById<ViewPager2>(R.id.viewpager)

    val adapter=Adapter(supportFragmentManager, lifecycle)

    viewPager2.adapter=adapter

    val home = findViewById<ImageView>(R.id.home)
    home.setOnClickListener(){
        val intent = Intent(this, MainActivity::class.java)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY)
        startActivity(intent)
    }

    val news = findViewById<ImageView>(R.id.news)
    news.setOnClickListener(){
        val intent = Intent(this, News::class.java)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY)
        startActivity(intent)
    }

    val weather = findViewById<ImageView>(R.id.weather)
    weather.setOnClickListener(){
        val intent = Intent(this, Weather::class.java)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_ANIMATION)
        intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY)
        startActivity(intent)
    }
}
```