package com.example.githubapi.retrofit

import com.example.githubapi.model.UserInfo
import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path

interface API {
    @GET("users/{username}")
    fun getGithubInfo(@Path("username")username:String):Call<UserInfo>
}