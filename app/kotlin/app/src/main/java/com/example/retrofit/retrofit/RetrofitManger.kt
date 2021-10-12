package com.example.retrofit.retrofit

import android.util.Log
import com.example.retrofit.model.Photo
import com.example.retrofit.utils.API
import com.example.retrofit.utils.Constants.TAG
import com.example.retrofit.utils.RESPONSE_STATE
import com.google.gson.JsonElement
import retrofit2.Call
import retrofit2.Response

class RetrofitManger {

    companion object {
        val instance = RetrofitManger()
    }

    //http 콜 만들기
    //레트로핏 인터페이스 가져오기
    private val iRetrofit : IRetrofit? = RetrofitClient.getClient(API.BASE_URL)?.create(IRetrofit::class.java)

    // 사진 검색 api 호출
    fun searchPhotos(searchTerm: String?, completion: (RESPONSE_STATE ,String) -> Unit){

        val term = searchTerm ?:""

        val call = iRetrofit?.searchPhotos(searchTerm = term) ?: return

        call.enqueue(object : retrofit2.Callback<JsonElement> {
            override fun onResponse(call: Call<JsonElement>, response: Response<JsonElement>) {
                Log.d(TAG, "Retrofit - onResponse() called / response : ${response.body()}")

                when (response.code()) {
                    200 -> {
                        response.body()?.let {
                            var parsedPhotoDataArray = ArrayList<Photo>()
                            val body = it.asJsonObject
                            val results = body.getAsJsonArray("results")
                            val total = body.get("total").asInt
                            Log.d(TAG, "RetrofitManager - onReponse() called / total: $total")
                            results.forEach { resultItem ->
                                val resultItemObject = resultItem.asJsonObject
                                val user = resultItemObject.get("user").asJsonObject
                            }
                        }
                        completion(RESPONSE_STATE.OKAY, response.body().toString())
                    }
                }
            }

            override fun onFailure(call: Call<JsonElement>, t: Throwable) {
                Log.d(TAG, "Retrofit - onFailure() called / t: $t")
                completion(RESPONSE_STATE.FAIL, t.toString())
            }

        })
    }
}