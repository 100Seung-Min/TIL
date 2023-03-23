package com.example.school.dto

import java.util.*

data class BoardDTO(
    val num: Int,
    val title: String,
    val writer: String,
    val date: Date,
    val count: Int
)
