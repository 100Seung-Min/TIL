package com.example.retrofit.retrofit

import android.os.Handler
import android.os.Looper
import android.util.Log
import android.widget.Toast
import com.example.retrofit.App
import com.example.retrofit.utils.API
import com.example.retrofit.utils.Constants.TAG
import com.example.retrofit.utils.isJsonArray
import com.example.retrofit.utils.isJsonObject
import okhttp3.Interceptor
import okhttp3.OkHttpClient
import okhttp3.Response
import okhttp3.logging.HttpLoggingInterceptor
import org.json.JSONObject
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.lang.Exception
import java.util.concurrent.TimeUnit

object RetrofitClient {
    private var retrofitClient: Retrofit? = null
//    private lateinit var retrofitClient: Retrofit

    //클라이언트 가져오기
    fun getClient(baseUrl: String):Retrofit? {
        Log.d(TAG, "RetrofitClient - getClient() called")

        //okhttp 인스턴스 생성
        val client = OkHttpClient.Builder()

        //로그를 찍기 위해 로깅 인터셉터 추가
        val loggingInterceptor = HttpLoggingInterceptor(object : HttpLoggingInterceptor.Logger {
            override fun log(message: String) {
                Log.d(TAG, "RetrofitClient - log() called / message: $message")

                when {
                    message.isJsonObject() ->
                        Log.d(TAG, JSONObject(message).toString(4))
                    message.isJsonArray() ->
                        Log.d(TAG, JSONObject(message).toString(4))
                    else -> {
                        try{
                            Log.d(TAG, JSONObject(message).toString(4))
                        } catch (e: Exception){
                            Log.d(TAG, message)
                        }

                    }
                }
            }

        })

        loggingInterceptor.setLevel(HttpLoggingInterceptor.Level.BODY)

        //위에서 설정한 로깅 인터셉터를 okhttp 클라이언트에 추가
        client.addInterceptor(loggingInterceptor)

        //기본 파라미터 추가
        val baseParameterInterceptor : Interceptor = (object : Interceptor{
            override fun intercept(chain: Interceptor.Chain): Response {
                Log.d(TAG, "Retrofit - intercept() called")

                //오리지널 리퀘스트트
               val originalRequest = chain.request()

                // 클라이언트 아이디 넣어줌
                //쿼리 파라미터 추가
                val addedUrl = originalRequest.url.newBuilder()
                    .addQueryParameter("client_id", API.CLIENT_ID)
                    .build()

                val finalRequest = originalRequest.newBuilder()
                    .url(addedUrl)
                    .method(originalRequest.method, originalRequest.body)
                    .build()

                val response: Response = chain.proceed(finalRequest)

                if(response.code != 200){
                    Handler(Looper.getMainLooper()).post{
                        Toast.makeText(App.instance, "${response.code} 에러 입니다.", Toast.LENGTH_SHORT).show()
                    }
                }
                return response
            }

        })
        client.addInterceptor(baseParameterInterceptor)

        client.connectTimeout(10, TimeUnit.SECONDS)
        client.readTimeout(10, TimeUnit.SECONDS)
        client.writeTimeout(10, TimeUnit.SECONDS)
        client.retryOnConnectionFailure(true)


        //레트로핏 빌더를 통해 인스턴스 생성
        if(retrofitClient == null){
            retrofitClient = Retrofit.Builder()
                .baseUrl(baseUrl)
                .addConverterFactory(GsonConverterFactory.create())

                    //설정한 클라이언트로 레트로핏 클라이언트를 설정
                .client(client.build())
                .build()
        }
        return retrofitClient
    }
}