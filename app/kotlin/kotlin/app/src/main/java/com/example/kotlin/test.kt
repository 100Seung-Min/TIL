package com.example.kotlin

fun main(){
    hello()
    println(add(4, 5))
}

fun hello() : Unit{
    println("Hello World")
}

fun add(a : Int, b: Int) : Int{
    return a+b
}