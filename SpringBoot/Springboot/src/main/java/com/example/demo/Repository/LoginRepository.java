package com.example.demo.Repository;

import com.example.demo.DTO.LoginMember;
import org.springframework.stereotype.Repository;
import org.springframework.web.bind.annotation.PostMapping;

import javax.annotation.PostConstruct;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;

@Repository
public class LoginRepository {
    private static Map<Long, LoginMember> store = new ConcurrentHashMap<>();
    private static long sequence = 0L;

    public LoginMember save(LoginMember member){
        member.setId(++sequence);
        store.put(member.getId(), member);
        return member;
    }

    public LoginMember findById(Long id){
        return store.get(id);
    }

    public Optional<LoginMember> findByLoginId(String loginId){
        return this.findAll().stream()
                .filter(m -> m.getLoginId().equals(loginId))
                .findFirst();
    }

    public List<LoginMember> findAll(){
        return new ArrayList<>(store.values());
    }

    public void clearStore(){
        store.clear();
    }

    @PostConstruct
    public void init(){
        LoginMember member = new LoginMember();
        member.setLoginId("test");
        member.setPassword("test!");
        member.setName("테스터");
        save(member);
    }
}
