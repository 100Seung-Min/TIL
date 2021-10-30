package com.example.todolist

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.adapter.NoteAdapter
import com.example.todolist.data.Note
import com.example.todolist.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    val binding by lazy { ActivityMainBinding.inflate(layoutInflater)}

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val mainFragment = MainFragment()
        supportFragmentManager.beginTransaction().replace(R.id.container, mainFragment).commit()
        binding.saveBtn.setOnClickListener {
            Toast.makeText(this, "추가되었습니다.", Toast.LENGTH_SHORT).show()
        }
    }
}