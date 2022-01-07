package com.example.studymvvm.data.api

import com.example.studymvvm.data.model.RepoModel
import com.example.studymvvm.data.model.RepoSearchResponse
import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path
import retrofit2.http.Query

interface RepoApi {
    @GET("search/repositories")
    fun searchRepositories(@Query("q") query: String): Call<RepoSearchResponse>

    @GET("repos/{owner}/{name}")
    fun getRepository(
        @Path("owner") ownerLogin: String,
        @Path("name") repoName: String
    ): Call<RepoModel>
}
