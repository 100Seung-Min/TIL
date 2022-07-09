package com.example.study_board.config.auth.dto;

import com.example.study_board.domain.user.Client;
import lombok.Getter;

import java.io.Serializable;

@Getter
public class SessionUser implements Serializable {
    private String name;
    private String email;
    private String picture;

    public SessionUser(Client client) {
        this.name = client.getName();
        this.email = client.getEmail();
        this.picture = client.getPicture();
    }
}
