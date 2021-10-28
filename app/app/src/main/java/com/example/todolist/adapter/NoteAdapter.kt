package com.example.todolist.adapter

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.example.todolist.R
import com.example.todolist.data.Note

class NoteAdapter(val itemlist: ArrayList<Note>, val context: Context): RecyclerView.Adapter<NoteAdapter.ViewHolder>() {
    class ViewHolder(v: View): RecyclerView.ViewHolder(v){
        fun bind(item: Note, context: Context){
            itemView.findViewById<Button>(R.id.delete_btn).setOnClickListener {
                Toast.makeText(context, "클릭", Toast.LENGTH_SHORT).show()
            }
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.todo_item, parent, false)
        return NoteAdapter.ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.bind(itemlist[position], context)
    }

    override fun getItemCount(): Int {
        return itemlist.size
    }
}