package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.kotlin.adapter.Member
import com.example.kotlin.databinding.RecyclerMainBinding

class RecyclerView: AppCompatActivity() {

    private lateinit var binding: RecyclerMainBinding

    private val data:MutableList<Member> = mutableListOf()
    var i =4

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = RecyclerMainBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)

        initialize()
        refreshRecyclerView()

        binding.fab.setOnClickListener(){
            val string = "Member$i"
            i++
            data.add(Member(string))
            refreshRecyclerView()
        }
    }

    private fun initialize() {
        with(data){
            add(Member("Member1"))
            add(Member("Member2"))
            add(Member("Member3"))
        }
    }

    private fun refreshRecyclerView(){
        val adapter = MyAdapter()
        adapter.listData = data
        binding.recyclerView.adapter = adapter
        binding.recyclerView.layoutManager = LinearLayoutManager(this)
    }
}