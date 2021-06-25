package com.example.kotlin

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val button : Button = findViewById(R.id.btn1)
        button.setOnClickListener{
            makeToast()

        }
    }

    fun makeToast(){
        val text="승민아?"
        val toast = Toast.makeText(applicationContext,text,Toast.LENGTH_SHORT)
        toast.show()
    }
}