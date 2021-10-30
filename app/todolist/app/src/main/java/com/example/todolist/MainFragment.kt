package com.example.todolist

import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.adapter.NoteAdapter
import com.example.todolist.data.Note

class MainFragment: Fragment() {
    val TAG = "오류"
    var itemlist: ArrayList<Note> = ArrayList()

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_main, container, false)
        itemlist.add(Note(0, "공부하기"))
        view.findViewById<RecyclerView>(R.id.recyclerview).adapter = NoteAdapter(itemlist)
        return view
    }
}