package com.example.kotlin

import android.annotation.SuppressLint
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import com.example.kotlin.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding : ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        setContentView(R.layout.activity_main)

        Toast.makeText(this,"welcome",Toast.LENGTH_SHORT).show()

        binding.btn1.setOnClickListener{
            val text = "로그인 되었습니다"
            Toast.makeText(this,text,Toast.LENGTH_SHORT).show()
            val intent = Intent(this, Calculator::class.java)
            startActivity(intent)
        }
    }
}