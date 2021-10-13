package com.example.retrofit

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Handler
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.core.widget.addTextChangedListener
import com.example.retrofit.databinding.ActivityMainBinding
import com.example.retrofit.retrofit.RetrofitManger
import com.example.retrofit.utils.Constants.TAG
import com.example.retrofit.utils.RESPONSE_STATUS
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

        //검색 버튼 클릭시
       mbinding.btnSearch.setOnClickListener {
           Log.d(TAG, "MainActivity -검색버튼이 클릭되었다. / currentSearchType : $currentSearchType")

           val userSearchInput = mbinding.searchTermEditText.text.toString()

           this.handleSearchButtonUi()

           //검색 api 호출
            RetrofitManger.instance.searchPhotos(searchTerm = mbinding.searchTermEditText.text.toString(), completion = {
                reponseState, responseDataArrayList ->
                when(reponseState){
                    RESPONSE_STATUS.OKAY -> {
                        Log.d(TAG, "api 호출 성공 : ${responseDataArrayList?.size}")
                        val intent = Intent(this, PhotoCollectionActivity::class.java)
                        val bundle = Bundle()
                        bundle.putSerializable("photo_array_list", responseDataArrayList)
                        intent.putExtra("array_bundle", bundle)
                        intent.putExtra("search_term", userSearchInput)
                        startActivity(intent)
                    }
                    RESPONSE_STATUS.FAIL -> {
                        Toast.makeText(this, "api 호출 에러", Toast.LENGTH_SHORT).show()
                        Log.d(TAG, "api 호출 실패 : ${responseDataArrayList}")
                    }
                    RESPONSE_STATUS.NO_CONTENT -> {
                        Toast.makeText(this, "검색결과가 없습니다.", Toast.LENGTH_SHORT).show()
                    }
                }
                mbinding.btnProgress.visibility = View.INVISIBLE
                mbinding.btnSearch.text = "검색"
                mbinding.searchTermEditText.setText("")
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