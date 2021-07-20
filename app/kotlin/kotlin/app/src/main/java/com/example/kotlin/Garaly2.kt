package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.viewpager2.widget.ViewPager2
import com.example.kotlin.adapter.ViewPager2Adapter
import com.google.android.material.tabs.TabLayout
import com.google.android.material.tabs.TabLayoutMediator

class Garaly2: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.fragment_main)

        val tabLayout=findViewById<TabLayout>(R.id.tab_layout)
        val viewpager2=findViewById<ViewPager2>(R.id.view_pager_2)

        val adapter=ViewPager2Adapter(supportFragmentManager, lifecycle)

        viewpager2.adapter=adapter

        TabLayoutMediator(tabLayout, viewpager2) {tab, position ->
            when (position){
                0 -> {
                    tab.text="First"
                }
                1 -> {
                    tab.text="Second"
                }
                2 -> {
                    tab.text="Third"
                }
                3 -> {
                    tab.text="Forth"
                }
            }
        }.attach()
    }
}