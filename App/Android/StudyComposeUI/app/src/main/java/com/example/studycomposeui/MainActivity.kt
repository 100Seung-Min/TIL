package com.example.studycomposeui

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.animation.animateColorAsState
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.studycomposeui.ui.theme.Purple200
import com.example.studycomposeui.ui.theme.StudyComposeUITheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            myApp {
                MyScreenContent(listOf("안드로이드", "컴포즈"))
            }
        }
    }
}

@Composable
fun myApp(content: @Composable () -> Unit) {
    StudyComposeUITheme {
        Surface(
            modifier = Modifier.padding(24.dp),
            color = Purple200
        ) {
            content()
        }
    }
}

@Composable
fun MyScreenContent() {
    Column {
        Greeting(name = "안드로이드")
        Divider(color = Color.Black)
        Greeting(name = "컴포즈")
    }
}

@Composable
fun MyScreenContent(names: List<String>) {
    val countState = remember{ mutableStateOf(0)}
    Column(modifier = Modifier.fillMaxHeight()) {
        Column(modifier = Modifier.weight(1f)) {
            names.forEach {
                Greeting(name = it)
                Divider(color = Color.Black)
            }
        }

        NameList(names = names, modifier = Modifier.weight(1f))

        Divider(color = Color.Transparent, thickness = 32.dp)
        Counter(
            count = countState.value,
            updateCount = {
                countState.value = it
            }
        )
    }
}

@Composable
fun Greeting(name: String) {
    var isSelected by remember { mutableStateOf(false) }
    val backgroundColor by animateColorAsState(if (isSelected) Color.Red else Color.Transparent)


    Text(text = "Hello $name!",
        modifier = Modifier
            .padding(24.dp)
            .background(color = backgroundColor)
            .clickable(onClick = { isSelected = !isSelected }),
        style = MaterialTheme.typography.h1
    )
}

@Composable
fun Counter(count: Int, updateCount: (Int) -> Unit) {
    Button(
        onClick = {updateCount(count+1)},
        colors = ButtonDefaults.buttonColors(
            backgroundColor = if(count > 5) Color.Cyan else Color.White
        )
    ) {
        Text(text = "${count}번 클릭했습니다")
    }
}

@Composable
fun Counter() {
    val count = remember{ mutableStateOf(0)}
    
    Button(onClick = { count.value++ }) {
        Text(text = "${count.value}번 클릭했습니다")
    }
}

@Composable
fun NameList(names: List<String>, modifier: Modifier) {
    LazyColumn(modifier = modifier) {
        items(items = names) { name ->
            Greeting(name = name)
            Divider(color = Color.Black)
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    myApp {
        MyScreenContent()
    }
}