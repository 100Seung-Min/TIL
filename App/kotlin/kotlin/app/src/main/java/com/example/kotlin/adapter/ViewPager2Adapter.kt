package com.example.kotlin.adapter

import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentManager
import androidx.lifecycle.Lifecycle
import androidx.viewpager2.adapter.FragmentStateAdapter
import com.example.kotlin.flagment.FirstFragment
import com.example.kotlin.flagment.ForthFragment
import com.example.kotlin.flagment.SecFragment
import com.example.kotlin.flagment.ThirdFragment

class ViewPager2Adapter(fragmentManager: FragmentManager, lifecycle: Lifecycle): FragmentStateAdapter(fragmentManager, lifecycle){
    override fun getItemCount(): Int {
        return 4
    }

    override fun createFragment(position: Int): Fragment {
        return when(position){
            0 -> {
                FirstFragment()
            }
            1 -> {
                SecFragment()
            }
            2 -> {
                ThirdFragment()
            }
            3 -> {
                ForthFragment()
            }
            else -> {
                Fragment()
            }
        }
    }
}