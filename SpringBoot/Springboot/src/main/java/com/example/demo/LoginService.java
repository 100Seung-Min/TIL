package com.example.demo;

import com.example.demo.DTO.LoginMember;
import com.example.demo.Repository.LoginRepository;
import com.example.demo.Repository.MemberRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

@RequiredArgsConstructor
@Service
public class LoginService {
    private final LoginRepository memberRepository;

    public LoginMember Login(String loginId, String password){
        return memberRepository.findByLoginId(loginId)
                .filter(m -> m.getPassword().equals(password))
                .orElse(null);
    }
}
