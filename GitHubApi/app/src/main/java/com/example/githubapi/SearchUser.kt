package com.example.githubapi

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.githubapi.databinding.ActivitySearchUserBinding

class SearchUser : AppCompatActivity() {
    val binding by lazy {ActivitySearchUserBinding.inflate(layoutInflater)}
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)
        binding.findBtn.setOnClickListener {
            val text = binding.usernameEdit.text.toString()
            val intent = Intent(this, MainActivity::class.java)
            intent.putExtra("username", text)
            startActivity(intent)
        }
    }
}