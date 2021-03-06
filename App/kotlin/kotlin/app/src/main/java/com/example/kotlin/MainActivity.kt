package com.example.kotlin

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.kotlin.databinding.MainBinding

class MainActivity : AppCompatActivity(){

    private lateinit var binding: MainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = MainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.calculator.setOnClickListener(){
            val intent = Intent(this, Calculator::class.java)
            startActivity(intent)
        }

        binding.galary.setOnClickListener(){
            val intent = Intent(this, Garaly2::class.java)
            startActivity(intent)
        }

        binding.galary1.setOnClickListener() {
            val intent = Intent(this, Garaly::class.java)
            startActivity(intent)
        }

        binding.recycler.setOnClickListener() {
            val intent = Intent(this, RecyclerView::class.java)
            startActivity(intent)
        }
    }
}