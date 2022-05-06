package com.login.login

import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.runApplication

@SpringBootApplication
open class LoginApplication

fun main(args: Array<String>) {
	runApplication<LoginApplication>(*args)
}
