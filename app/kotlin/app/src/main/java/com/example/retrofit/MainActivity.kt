package com.example.retrofit

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import com.example.retrofit.databinding.ActivityMainBinding
import com.example.retrofit.retrofit.RetrofitManger
import com.example.retrofit.utils.Constants.TAG
import com.example.retrofit.utils.RESPONSE_STATE

class MainActivity : AppCompatActivity() {

    val mbinding by lazy { ActivityMainBinding.inflate(layoutInflater)}

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(mbinding.root)

        mbinding.btn.setOnClickListener {
            RetrofitManger.instance.searchPhotos(searchTerm = mbinding.editTxt.toString(), completion = {
                reponseState, responseBody ->
                when(reponseState){
                    RESPONSE_STATE.OKAY -> {
                        Log.d(TAG, "api 호출 성공 : ${responseBody}")
                    }
                    RESPONSE_STATE.FAIL -> {
                        Toast.makeText(this, "api 호출 에러", Toast.LENGTH_SHORT).show()
                        Log.d(TAG, "api 호출 실패 : ${responseBody}")
                    }
                }
            })
        }
    }
}