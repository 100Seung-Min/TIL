package com.example.studymvvm.data.model

import android.content.Context
import android.text.TextUtils
import com.example.studymvvm.ui.model.RepoItem
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
        "Description"
    else
        description,

    language = if(TextUtils.isEmpty(language))
        "Language"
    else
        language,

    updatedAt = try{
        com.example.studymvvm.utils.DateUtils.dateFormatToShow.format(updatedAt)
    } catch (e: IllegalArgumentException){
        "Unknown"
    },

    stars = stars.toString()
)
