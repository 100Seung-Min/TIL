package com.example.databinding

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import androidx.databinding.DataBindingUtil
import com.example.databinding.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    var text = "안녕"
    var user = User(null, "백승민", "17")

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        binding = DataBindingUtil.setContentView(this, R.layout.activity_main)
        binding.activity = this

    }

    fun change(){
        binding.apply {
            btn.setOnClickListener {
                text1.visibility = View.VISIBLE
                text1.text = "성공"
            }
        }
    }
}