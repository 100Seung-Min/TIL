package com.example.studymvvm.data.model

import android.content.Context
import android.text.TextUtils
import android.text.format.DateUtils
import com.example.studymvvm.R
import com.google.gson.annotations.SerializedName
import java.lang.IllegalArgumentException

data class RepoModel(
    @SerializedName("name")
    val name: String,
    @SerializedName("full_name")
    val fullName: String,
    @SerializedName("owner")
    val owner: OwnerModel,
    @SerializedName("description")
    val description: String,
    @SerializedName("language")
    val language: String,
    @SerializedName("updated_at")
    val updatedAt: String,
    @SerializedName("stargazers_count")
    val stars: Int
){
    data class OwnerModel(
        @SerializedName("login")
        val login: String,
        @SerializedName("avatar_url")
        val avatarUrl: String
    )
}

fun RepoModel.mapToPresentation(context: Context) = RepoItem(
    title = fullName,
    repoName = name,
    owner = RepoItem.OwnerItem(
        ownerName = owner.login,
        ownerUrl = owner.avatarUrl
    ),

    description = if(TextUtils.isEmpty(description))
        "설명이 없습니다"
    else
        description,

    language = if(TextUtils.isEmpty(language))
        "언어가 없습니다"
    else
        language,

    updatedAt = try{
        updatedAt
    } catch (e: IllegalArgumentException){
        "알 수 없음"
    },

    stars = stars.toString()
)
