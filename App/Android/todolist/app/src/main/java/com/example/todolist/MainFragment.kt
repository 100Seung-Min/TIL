package com.example.todolist

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.adapter.NoteAdapter
import com.example.todolist.data.Note

class MainFragment(var itemlist: ArrayList<Note>): Fragment() {
    val TAG = "오류"

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_main, container, false)
        view.findViewById<RecyclerView>(R.id.recyclerview).adapter = NoteAdapter(itemlist)
        view.findViewById<RecyclerView>(R.id.recyclerview).layoutManager = LinearLayoutManager(context)
        return view
    }
}