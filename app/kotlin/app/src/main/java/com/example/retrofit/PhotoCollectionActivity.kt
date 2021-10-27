package com.example.retrofit

import android.app.SearchManager
import android.content.Context
import android.graphics.Color
import android.os.Bundle
import android.text.InputFilter
import android.util.Log
import android.view.Menu
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.AppCompatEditText
import androidx.appcompat.widget.SearchView
import androidx.recyclerview.widget.GridLayoutManager
import com.example.retrofit.databinding.ActivityPhotoCollectionBinding
import com.example.retrofit.model.Photo
import com.example.retrofit.recyclerview.PhotoGridRecyclerViewAdapter
import com.example.retrofit.utils.Constants.TAG

class PhotoCollectionActivity:AppCompatActivity(),SearchView.OnQueryTextListener {

    val binding by lazy { ActivityPhotoCollectionBinding.inflate(layoutInflater) }

    //데이터
    private var photoList = ArrayList<Photo>()

    //어댑터
    private lateinit var photoGridRecyclerViewAdapter: PhotoGridRecyclerViewAdapter

    //서치뷰
    private lateinit var mySearchView: SearchView

    //서치뷰 에딧 텍스트
    private lateinit var mySearchViewEditText: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val bundle = intent.getBundleExtra("array_bundle")
        val searchTerm = intent.getStringExtra("search_term")
        photoList = bundle?.getSerializable("photo_array_list") as ArrayList<Photo>
        Log.d(TAG, "PhotoCollectionActivity - onCreate() called / searchTerm : $searchTerm, photoList.count() : ${photoList.count()}")

        binding.topAppBar.title = searchTerm

        setSupportActionBar(binding.topAppBar)

        this.photoGridRecyclerViewAdapter = PhotoGridRecyclerViewAdapter()
        this.photoGridRecyclerViewAdapter.submitList(photoList)

        binding.myPhotoRecyclerView.layoutManager = GridLayoutManager(this, 2, GridLayoutManager.VERTICAL, false)
        binding.myPhotoRecyclerView.adapter = this.photoGridRecyclerViewAdapter
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        Log.d(TAG, "PhotoCollectActivity - onCreateOptionsMenu() called")
        val inflater = menuInflater
        inflater.inflate(R.menu.top_app_bar_menu, menu)
        val searchManager = getSystemService(Context.SEARCH_SERVICE) as SearchManager
        this.mySearchView = menu?.findItem(R.id.search_menu_item)?.actionView as SearchView
        this.mySearchView.apply {
            this.queryHint = "검색어를 입력해주세요"
            this.setOnQueryTextListener(this@PhotoCollectionActivity)
            this.setOnQueryTextFocusChangeListener { _, hasExpaned ->
                when(hasExpaned){
                    true -> {
                        Log.d(TAG, "서치뷰 열림")
                    }
                    false -> {
                        Log.d(TAG, "서치뷰 닫힘")
                    }
                }
            }

            //서치뷰에서 에딧텍스트를 가져온다
            mySearchViewEditText = this.findViewById(androidx.appcompat.R.id.search_src_text)
        }
        this.mySearchViewEditText.apply {
            this.filters = arrayOf(InputFilter.LengthFilter(12))
            this.setTextColor(Color.WHITE)
            this.setHintTextColor(Color.WHITE)
        }
        return true
    }

    override fun onQueryTextChange(newText: String?): Boolean {
        Log.d(TAG, "PhotoCollectionActivity onQueryTextChange() called / query: $newText")
        return true
    }

    //검색어 입력 이벤트
    override fun onQueryTextSubmit(query: String?): Boolean {
        Log.d(TAG, "PhotoCollectionActivity - onQueryTextSubmit() called / query : $query")
        val userInputText = query ?: ""
        if(userInputText.count() == 12){
            Toast.makeText(this, "검색어는 12자 까지만 입력 가능합니다.", Toast.LENGTH_SHORT).show()
        }
        return true
    }
}