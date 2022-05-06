package com.example.demo.Repository;

import com.example.demo.DTO.MemberEntity;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MemberRepository extends JpaRepository<MemberEntity, Long>{

}
