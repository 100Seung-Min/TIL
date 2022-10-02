package com.example.studymvvm.data.api

import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.util.concurrent.TimeUnit

object ApiProvider {
    private const val baseUrl = "https://api.github.com/"

    private fun getRetrofitBuilder() = Retrofit.Builder()
        .baseUrl(baseUrl)
        .client(getOkHttpClient())
        .addConverterFactory(GsonConverterFactory.create())
        .build()

    private fun getOkHttpClient() = OkHttpClient.Builder().apply {
        readTimeout(60, TimeUnit.SECONDS)
        connectTimeout(60, TimeUnit.SECONDS)
        writeTimeout(5, TimeUnit.SECONDS)

        addInterceptor(getLoggingIntercepter())
    }.build()

    private fun getLoggingIntercepter() = HttpLoggingInterceptor().apply {
        level = HttpLoggingInterceptor.Level.BODY
    }

    fun provideRepoApi(): RepoApi = getRetrofitBuilder().create(RepoApi::class.java)

    fun provideUserApi(): UserApi = getRetrofitBuilder().create(UserApi::class.java)
}