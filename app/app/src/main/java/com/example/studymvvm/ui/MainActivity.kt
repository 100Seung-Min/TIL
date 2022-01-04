package com.example.studymvvm.ui

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.studymvvm.R

class MainActivity: AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initTitle()
        initMainFragment()
    }

    private fun initTitle(){
        title = "Search Repository"
    }

    private fun initMainFragment(){
        supportFragmentManager
            .beginTransaction()
            .add(R.id.lylFragmentContainer, SearchFragment.newInstance())
            .commit()
    }

    fun goToDetailFragment(ownerName: String, repoName: String){
        supportFragmentManager
            .beginTransaction()
            .add(R.id.lylFragmentContainer, DetailFragment.newInstance(ownerName, repoName))
            .addToBackStack(null)
            .commit()
    }
}