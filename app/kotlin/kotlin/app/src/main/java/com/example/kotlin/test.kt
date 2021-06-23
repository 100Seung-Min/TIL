package com.example.kotlin

fun main(){
    hello()
    println(add(4, 5))
    name()
    forandwhile()
}

//1. 함수
fun hello() : Unit{
    println("Hello World")
}
fun add(a : Int, b: Int) : Int{
    return a+b
}

//2. var and val
fun hi(){
    var a = 10;
    val b = 10;
    a= 20;
}

//3. string template
fun name(){
    var named = "baek"
    println("my name is ${named}")
}

//4. 조건식
fun max(a : Int, b : Int): Int = if(a>b)a else b
fun cheknum(score : Int){
    when(score){
        in 1..10 -> println("1~10")
        in 20..30 -> println("20 ~ 30")
        30,31 -> println("30 or 31")
        else -> println("null")
    }
}

//5. Array and List
fun arr(){
    val array:Array<Int> = arrayOf(1,2,3)
}
fun li(){
    val list:List<Int> = listOf(1,2,3)
    var arraylist = arrayListOf<Int>()
    arraylist.add(10)
    arraylist.add(20)
}

//6. for and while
fun forandwhile(){
    val students = arrayListOf("baek", "seung","min")

    for(name in students) {
        println("${name}")
    }
    var index = 0
    while(index < 10){
        println(index)
        index++
    }
}