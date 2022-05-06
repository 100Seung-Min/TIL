package com.example.demo.DTO;

import lombok.Data;

@Data
public class LoginMember {
    private long id;
    private String loginId;
    private String name;
    private String password;
}
