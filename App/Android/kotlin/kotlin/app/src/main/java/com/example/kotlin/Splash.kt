package com.example.kotlin

import android.os.Handler
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import android.content.Intent

class Splash : AppCompatActivity(){

    lateinit var handler: Handler

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.splash)

        handler = Handler()
        handler.postDelayed({
            val intent = Intent(this,Login::class.java)
            startActivity(intent)
            finish()
        }, 2000)
    }
}