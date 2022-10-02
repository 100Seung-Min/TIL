package com.example.retrofit.recyclerview

import android.util.Log
import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.example.retrofit.App
import com.example.retrofit.R
import com.example.retrofit.model.Photo
import com.example.retrofit.utils.Constants.TAG

class PhotoItemViewHolder(itemView: View): RecyclerView.ViewHolder(itemView) {

    private val photoImageView = itemView.findViewById<ImageView>(R.id.photo_image)
    private val photoCreatedAtText = itemView.findViewById<TextView>(R.id.created_at_text)
    private val photoLikesCountText = itemView.findViewById<TextView>(R.id.likes_count_text)

    fun bindWithView(photoItem: Photo){
        Log.d(TAG, "PhotoItemViewHolder - bindWithView() called")
        photoCreatedAtText.text = photoItem.createAt
        photoLikesCountText.text = photoItem.likeCount.toString()
        Glide.with(App.instance)
                .load(photoItem.thumnail)
                .placeholder(R.drawable.ic_baseline_insert_photo_24)
                .into(photoImageView)
    }
}