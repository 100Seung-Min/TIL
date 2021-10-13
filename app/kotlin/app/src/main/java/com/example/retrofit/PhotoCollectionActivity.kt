package com.example.retrofit

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.GridLayoutManager
import com.example.retrofit.databinding.ActivityPhotoCollectionBinding
import com.example.retrofit.model.Photo
import com.example.retrofit.recyclerview.PhotoGridRecyclerViewAdapter
import com.example.retrofit.utils.Constants.TAG

class PhotoCollectionActivity:AppCompatActivity() {

    val binding by lazy { ActivityPhotoCollectionBinding.inflate(layoutInflater) }

    //데이터
    private var photoList = ArrayList<Photo>()

    //어댑터
    private lateinit var photoGridRecyclerViewAdapter: PhotoGridRecyclerViewAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val bundle = intent.getBundleExtra("array_bundle")
        val searchTerm = intent.getStringExtra("search_term")
        photoList = bundle?.getSerializable("photo_array_list") as ArrayList<Photo>
        Log.d(TAG, "PhotoCollectionActivity - onCreate() called / searchTerm : $searchTerm, photoList.count() : ${photoList.count()}")

        binding.topAppBar.title = searchTerm

        this.photoGridRecyclerViewAdapter = PhotoGridRecyclerViewAdapter()
        this.photoGridRecyclerViewAdapter.submitList(photoList)

        binding.myPhotoRecyclerView.layoutManager = GridLayoutManager(this, 2, GridLayoutManager.VERTICAL, false)
        binding.myPhotoRecyclerView.adapter = this.photoGridRecyclerViewAdapter
    }
}