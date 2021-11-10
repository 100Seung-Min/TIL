package com.example.githubapi.model

import com.google.gson.annotations.SerializedName

data class UserInfo(
    @SerializedName("login")
    val id: String,
    @SerializedName("avatar_url")
    val profile_img: String,
    val followers: Int,
    val following: Int
)
