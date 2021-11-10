package com.example.githubapi

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.bumptech.glide.Glide
import com.example.githubapi.databinding.ActivityMainBinding
import com.example.githubapi.model.UserInfo
import com.example.githubapi.retrofit.API
import com.example.githubapi.retrofit.RetrofitClient
import retrofit2.Call
import retrofit2.Response

class MainActivity : AppCompatActivity() {
    val binding by lazy { ActivityMainBinding.inflate(layoutInflater) }
    var userprofile: String = ""
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)
        val username = intent.getStringExtra("username")
        RetrofitClient.api.getGithubInfo(username.toString()).enqueue(object : retrofit2.Callback<UserInfo>{
            override fun onResponse(call: Call<UserInfo>, response: Response<UserInfo>) {
                val userinfo = response.body()!!
                binding.followerTxt.text = userinfo.followers.toString()
                binding.followingTxt.text = userinfo.following.toString()
                userprofile = userinfo.profile_img
                view()
                binding.userIdTxt.text = userinfo.id.toString()
            }

            override fun onFailure(call: Call<UserInfo>, t: Throwable) {
                TODO("Not yet implemented")
            }

        })
    }
    fun view(){
        Glide.with(this)
            .load(userprofile)
            .into(binding.profileImg)
    }
}