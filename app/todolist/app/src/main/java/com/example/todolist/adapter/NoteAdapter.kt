package com.example.todolist.adapter

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.CheckBox
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.R
import com.example.todolist.data.Note

class NoteAdapter(val itemlist: ArrayList<Note>): RecyclerView.Adapter<NoteAdapter.ViewHolder>() {
    class ViewHolder(v: View): RecyclerView.ViewHolder(v){
        fun bind(item: Note){
            itemView.findViewById<CheckBox>(R.id.checkbox).text = item.todo
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.todo_item, parent, false)
        return NoteAdapter.ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.bind(itemlist[position])
    }

    override fun getItemCount(): Int {
        return itemlist.size
    }
}