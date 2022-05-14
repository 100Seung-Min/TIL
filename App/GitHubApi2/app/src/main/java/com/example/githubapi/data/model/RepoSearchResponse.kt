package com.example.studymvvm.data.model

import com.example.studymvvm.data.model.RepoModel
import com.google.gson.annotations.SerializedName

data class RepoSearchResponse(
    @SerializedName("total_count")
    val totalCount: Int,
    @SerializedName("items")
    val items: List<RepoModel>
)