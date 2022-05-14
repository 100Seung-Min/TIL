package com.example.kotlin

import android.os.Bundle
import android.view.View
import android.widget.*
import androidx.appcompat.app.AppCompatActivity
import com.example.kotlin.databinding.SignupBinding

class Signup : AppCompatActivity() {
    private var _binding: SignupBinding? = null
    private val binding get() = _binding!!

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        _binding = SignupBinding.inflate(layoutInflater)
        setContentView(binding.root)
        setupSpinnerYear()
        binding.spinnerYear.onItemSelectedListener = object :AdapterView.OnItemSelectedListener {
            override fun onItemSelected(parent: AdapterView<*>?, view: View?, position: Int, id: Long) {
                binding.txtYear.text = "Selected: ${binding.spinnerYear.getItemAtPosition(position)}"
            }
            override fun onNothingSelected(p0: AdapterView<*>?) {

            }
        }

    }
    private fun setupSpinnerYear() {
        val years = resources.getStringArray(R.array.spinner_year)
        val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, years)
        binding.spinnerYear.adapter = adapter
    }
    private fun setupSpinnerHandler() {

    }
}