package com.example.todolist

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.EditText
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.adapter.NoteAdapter
import com.example.todolist.data.Note
import com.example.todolist.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    val binding by lazy { ActivityMainBinding.inflate(layoutInflater)}

    val itemlist = ArrayList<Note>()
    lateinit var mainFragment: MainFragment

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)

        val pref = getSharedPreferences("COUNT", MODE_PRIVATE)
        val count = pref.getInt("count", 0)

        mainFragment = MainFragment(itemlist)
        supportFragmentManager.beginTransaction().replace(R.id.container, mainFragment).commit()
        binding.saveBtn.setOnClickListener {
            val edit = pref.edit()
            itemlist.add(Note(count, findViewById<EditText>(R.id.input_to_do).text.toString()))
            edit.putInt("count", count+1)
            mainFragment = MainFragment(itemlist)
            supportFragmentManager.beginTransaction().replace(R.id.container, mainFragment).commit()
        }
    }
}