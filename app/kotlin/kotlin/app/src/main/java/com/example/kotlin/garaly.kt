package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class garaly: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.viewpage)

        val adapter=ViewPagerAdapter()
    }
}