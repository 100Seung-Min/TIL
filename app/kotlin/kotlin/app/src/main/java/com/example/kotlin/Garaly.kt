package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.kotlin.adapter.ViewPagerAdapter
import kotlinx.android.synthetic.main.viewmain.*

class Garaly: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.viewmain)

        var currentPosition=0

        val adapter = ViewPagerAdapter()
        pager.adapter=adapter

        right.setOnClickListener {
            if(currentPosition < 5)
                currentPosition+=1
            if(currentPosition == 5)
                currentPosition = 0
            pager.setCurrentItem(currentPosition, true)
        }
        left.setOnClickListener {
            if(currentPosition >= 0)
                currentPosition-=1
            if(currentPosition == -1)
                currentPosition = 5
            pager.setCurrentItem(currentPosition, true)
        }
    }
}