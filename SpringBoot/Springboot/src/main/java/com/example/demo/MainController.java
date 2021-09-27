package com.example.demo;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class MainController {
    @RequestMapping(value = "/")
    public String main(){
        return "main.html";
    }
    @RequestMapping(value = "/menu")
    public String menu(){
        return "menu.html";
    }
    @RequestMapping(value = "/promotion")
    public String promotion(){
        return "promotion.html";
    }
    @RequestMapping(value = "/survey")
    public String survey(){
        return "survey.html";
    }
}

