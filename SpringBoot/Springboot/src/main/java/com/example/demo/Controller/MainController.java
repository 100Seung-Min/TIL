package com.example.demo.Controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class MainController {
    @RequestMapping(value = "/")
    public String main(){
        return "main";
    }
    @RequestMapping(value = "/menu")
    public String menu(){
        return "menu";
    }
    @RequestMapping(value = "/promotion")
    public String promotion(){
        return "promotion";
    }
    @RequestMapping(value = "/survey")
    public String survey(){
        return "survey";
    }
}

