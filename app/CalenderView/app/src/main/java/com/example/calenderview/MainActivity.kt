package com.example.calenderview

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.CalendarView
import com.example.calenderview.databinding.ActivityMainBinding
import java.text.SimpleDateFormat
import java.util.*

class MainActivity : AppCompatActivity() {
    val binding by lazy {ActivityMainBinding.inflate(layoutInflater)}
    lateinit var date: String
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(binding.root)
        val pref = getSharedPreferences("text", MODE_PRIVATE)
        val edit = pref.edit()
        val day = Date()
        date = SimpleDateFormat("yyyyMMdd").format(day)
        binding.calendarview.setOnDateChangeListener(object : CalendarView.OnDateChangeListener{
            override fun onSelectedDayChange(
                view: CalendarView,
                year: Int,
                month: Int,
                dayOfMonth: Int
            ) {
                date = year.toString() + (month + 1).toString() + dayOfMonth.toString()
                binding.viewTxt.text = pref.getString(date, "내용없음")
            }
        })
        binding.saveBtn.setOnClickListener {
            edit.putString(date, binding.editTxt.text.toString())
            edit.commit()
            binding.viewTxt.text = pref.getString(date, "내용없음")
        }
        binding.viewTxt.text = pref.getString(date, "내용없음")
    }
}