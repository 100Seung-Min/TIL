package com.example.retrofit

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.text.TextWatcher
import android.util.Log
import android.view.View
import android.widget.FrameLayout
import android.widget.Toast
import androidx.core.widget.addTextChangedListener
import com.example.retrofit.databinding.ActivityMainBinding
import com.example.retrofit.retrofit.RetrofitManger
import com.example.retrofit.utils.Constants
import com.example.retrofit.utils.Constants.TAG
import com.example.retrofit.utils.RESPONSE_STATE
import com.example.retrofit.utils.SEARCH_TYPE

class MainActivity : AppCompatActivity() {

    val mbinding by lazy { ActivityMainBinding.inflate(layoutInflater)}

    private var currentSearchType: SEARCH_TYPE = SEARCH_TYPE.PHOTO

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(mbinding.root)

        Log.d(TAG, "MainActivity onCreate() called")

        //라디오 그룹 가져오기기
        mbinding.searchTermRadioGroup.setOnCheckedChangeListener { _, checkedId ->
            when(checkedId){
                R.id.photo_search_radio_btn -> {
                    Log.d(TAG, "사진검색 버튼 클릭")
                    mbinding.searchTermTextLayout.hint = "사진검색"
                    mbinding.searchTermTextLayout.startIconDrawable = resources.getDrawable(R.drawable.ic_baseline_photo_library_24, resources.newTheme())
                    this.currentSearchType = SEARCH_TYPE.PHOTO
                }
                R.id.user_search_radio_btn -> {
                    Log.d(TAG, "사용자검색 버튼 클릭")
                    mbinding.searchTermTextLayout.hint = "사용자검색"
                    mbinding.searchTermTextLayout.startIconDrawable = resources.getDrawable(R.drawable.ic_baseline_person_24, resources.newTheme())
                    this.currentSearchType = SEARCH_TYPE.USER
                }
            }
            Log.d(TAG, "MainActivity -onCheckedChanged() called / currentSearchType : $currentSearchType")
        }

        //텍스트가 변경되었을때
        mbinding.searchTermEditText.addTextChangedListener {
            //입력된 글자가 하나라도 있다면
            if(it.toString().count() > 0){
                //검색버튼을 보여준다.
                mbinding.frameSearchContent.visibility = View.VISIBLE
                mbinding.searchTermTextLayout.helperText = " "

                // 스크롤뷰를 올린다.
                mbinding.mainScrollview.scrollTo(0, 200)
            } else {
                mbinding.frameSearchContent.visibility = View.INVISIBLE
                mbinding.searchTermTextLayout.helperText = "검색어를 입력해주세요"
            }
            if (it.toString().count() == 12){
                Log.d(TAG, "MainActivity -에러띄우기")
                Toast.makeText(this, "검색어는 12자 까지만 입력 가능합니다.", Toast.LENGTH_SHORT).show()
            }
        }


       mbinding.btnSearch.setOnClickListener {
           Log.d(TAG, "MainActivity -검색버튼이 클릭되었다. / currentSearchType : $currentSearchType")
           this.handleSearchButtonUi()
            RetrofitManger.instance.searchPhotos(searchTerm = mbinding.searchTermEditText.toString(), completion = {
                reponseState, responseBody ->
                when(reponseState){
                    RESPONSE_STATE.OKAY -> {
                        Log.d(TAG, "api 호출 성공 : ${responseBody}")
                    }
                    RESPONSE_STATE.FAIL -> {
                        Toast.makeText(this, "api 호출 에러", Toast.LENGTH_SHORT).show()
                        Log.d(TAG, "api 호출 실패 : ${responseBody}")
                    }
                }
            })
        }
    } //onCreate

    private fun handleSearchButtonUi(){
        mbinding.btnProgress.visibility = View.VISIBLE
        mbinding.btnSearch.text = ""
        Handler().postDelayed({
            mbinding.btnProgress.visibility = View.INVISIBLE
            mbinding.btnSearch.text = "검색"
        }, 1500)
    }
}