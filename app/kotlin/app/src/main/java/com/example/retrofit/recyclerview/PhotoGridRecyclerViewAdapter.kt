package com.example.retrofit.recyclerview

import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.retrofit.App
import com.example.retrofit.R
import com.example.retrofit.model.Photo

class PhotoGridRecyclerViewAdapter : RecyclerView.Adapter<PhotoItemViewHolder>() {

    private var photoList = ArrayList<Photo>()

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): PhotoItemViewHolder {
        val photoItemViewHolder = PhotoItemViewHolder(LayoutInflater.from(parent.context).inflate(R.layout.layout_photo_item, parent, false))
        return photoItemViewHolder
    }

    override fun onBindViewHolder(holder: PhotoItemViewHolder, position: Int) {
        holder.bindWithView(this.photoList[position])
    }

    override fun getItemCount(): Int {
        return this.photoList.size
    }

    //외부에서 데이터를 넣어준다
    fun submitList(photo:ArrayList<Photo>){
        this.photoList = photo
    }
}