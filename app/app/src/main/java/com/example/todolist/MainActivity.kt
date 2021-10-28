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
    var itemlist: ArrayList<Note> = ArrayList()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val mainFragment = MainFragment()
        supportFragmentManager.beginTransaction().replace(R.id.container, mainFragment).commit()
        binding.saveBtn.setOnClickListener {
            Toast.makeText(this, "추가되었습니다.", Toast.LENGTH_SHORT).show()
        }
        findViewById<RecyclerView>(R.id.recyclerview).apply {
            val adapter = NoteAdapter(itemlist, context)
            this.adapter = adapter
            this.layoutManager = LinearLayoutManager(context)
        }
    }
}