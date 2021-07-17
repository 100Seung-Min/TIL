package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.viewmain.*

class garaly: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.viewmain)

        val adapter = ViewPagerAdapter()
        pager.adapter=adapter
    }
}