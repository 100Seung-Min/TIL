package com.example.kotlin

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.core.content.ContextCompat
import java.util.jar.Manifest

fun selectCamera(){
    var permission = ContextCompat.checkSelfPermission(this, Manifest)
}